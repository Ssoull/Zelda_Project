#include <iostream>

#include "tilemap.h"

TileMap::TileMap() : m_tiles(TILE_MAP_WIDTH * TILE_MAP_WIDTH)
{
    int y = 0;
    for (unsigned i = 0; i < m_tiles.size(); ++i)
    {
        if (i % TILE_MAP_WIDTH == 0 && i != 0 )
        {
            ++y;
        }

        m_tiles[i] = new Tile(TileType::Tree, Coordinates(i % TILE_MAP_WIDTH, y));
    }

    m_tiles[unsigned(5 * TILE_MAP_WIDTH + 5)]->updateTileType(TileType::Herb);
    m_tiles[unsigned(4 * TILE_MAP_WIDTH + 5)]->updateTileType(TileType::Herb);
    m_tiles[unsigned(5 * TILE_MAP_WIDTH + 6)]->updateTileType(TileType::Herb);
    m_tiles[unsigned(6 * TILE_MAP_WIDTH + 5)]->updateTileType(TileType::Herb);
    m_tiles[unsigned(5 * TILE_MAP_WIDTH + 4)]->updateTileType(TileType::Herb);
}

bool TileMap::checkCollisionWithGraphicObject(const GraphicObject &graphicObject) const
{
    bool nextPositionIsWalkable = this->checkWalkableTile(graphicObject.getCoordinates()); // Upper left
    nextPositionIsWalkable = !nextPositionIsWalkable ? nextPositionIsWalkable : this->checkWalkableTile(Coordinates(graphicObject.getX() + graphicObject.getWidth() - 1, graphicObject.getY())); // Upper right
    nextPositionIsWalkable = !nextPositionIsWalkable ? nextPositionIsWalkable : this->checkWalkableTile(Coordinates(graphicObject.getX() + graphicObject.getWidth() - 1, graphicObject.getY() + graphicObject.getHeight() - 1)); // Lower right
    nextPositionIsWalkable = !nextPositionIsWalkable ? nextPositionIsWalkable : this->checkWalkableTile(Coordinates(graphicObject.getX(), graphicObject.getY() + graphicObject.getHeight() - 1)); // Lower left

    return nextPositionIsWalkable;
}

bool TileMap::checkWalkableTile(const Coordinates &coordinates) const
{
    Coordinates tileCoord(coordinates.getX() / Tile::TILE_SIZE, coordinates.getY() / Tile::TILE_SIZE);

    return m_tiles[unsigned(TILE_MAP_WIDTH * tileCoord.getY() + tileCoord.getX())]->isWalkable();
}

TileMap::~TileMap()
{
    for (unsigned i = 0; i < m_tiles.size(); ++i)
    {
        if (m_tiles[i] != nullptr)
        {
            delete m_tiles[i];
        }
    }

    m_tiles.clear();
    m_tiles.shrink_to_fit();

    std::cout << "Tile Map: Passed in the destructor" << std::endl;
}

// GETTERS
Tile * TileMap::getTile(const unsigned index) const
{
    return m_tiles[index];
}

unsigned TileMap::getSizeTileMap() const
{
    return unsigned(m_tiles.size());
}

