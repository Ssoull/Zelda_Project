#include "tile.h"
#include <iostream>

Tile::Tile(const TileType tile_type, const Coordinates &tile_coord) :
    GraphicObject(Coordinates(tile_coord.getX() * tile_const::TILE_SIZE, tile_coord.getY() * tile_const::TILE_SIZE), Size(tile_const::TILE_SIZE)),
    m_tileCoord(new Coordinates(tile_coord))
{
    this->updateTileType(tile_type);
}

void Tile::updateTileType(const TileType tile_type)
{
    if (m_tileType != tile_type)
    {
        m_tileType = tile_type;

        switch(tile_type)
        {
        case TileType::Tree:
        case TileType::Water:
            walkable = false;
            break;

        case TileType::Grass:
        case TileType::Wooden_Bridge:
            walkable = true;
            break;
        }
    }
}

void Tile::updateTileCoord(const Coordinates &new_tile_coord)
{
    // We create a new Coordinates to avoid reference modification
    m_tileCoord->updateCoord(Coordinates(new_tile_coord));

    this->updateCoord(Coordinates(m_tileCoord->getX() * unsigned(this->getWidth()), m_tileCoord->getY() * unsigned(this->getHeight())));
}

// GETTERS
TileType Tile::getTileType() const
{
    return m_tileType;
}

bool Tile::isWalkable() const
{
    return walkable;
}

Tile::~Tile()
{
    if (m_tileCoord != nullptr)
    {
        delete m_tileCoord;
    }

    std::cout << "Tile: Passed in the destructor" << std::endl;
}
