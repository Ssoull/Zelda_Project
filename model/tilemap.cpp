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

