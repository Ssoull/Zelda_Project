#include <iostream>

#include "worldmap.h"

WorldMap::WorldMap() : m_tileMaps(worldmap_const::WORLD_MAP_WIDTH * worldmap_const::WORLD_MAP_WIDTH), m_currentIndexMap(worldmap_const::INDEX_START)
{
    for (unsigned int i = 0; i < m_tileMaps.size(); ++i)
    {
        m_tileMaps[i] = new TileMap(":/data/asset/map/" + std::to_string(i + 1) + ".data");
    }
}

void WorldMap::changeMap(const char direction)
{
    int newIndex = m_currentIndexMap;
    switch ( direction )
    {
    case 'z':
        newIndex -= worldmap_const::WORLD_MAP_WIDTH;
        break;
    case 's':
        newIndex += worldmap_const::WORLD_MAP_WIDTH;
        break;

    case 'q':
        --newIndex;
        break;

    case 'd':
        ++newIndex;
        break;

    default:
        std::cout << "Direction not recognized" << std::endl;
        break;
    }

    if (newIndex >= 0 && newIndex < worldmap_const::WORLD_MAP_WIDTH * worldmap_const::WORLD_MAP_WIDTH)
    {
        m_currentIndexMap = newIndex;
    }
}

WorldMap::~WorldMap()
{
    for (unsigned i = 0; i < m_tileMaps.size(); ++i)
    {
        if (m_tileMaps[i] != nullptr)
        {
            delete m_tileMaps[i];
        }
    }

    m_tileMaps.clear();
    m_tileMaps.shrink_to_fit();

    std::cout << "World Map: Passed in the destructor" << std::endl;
}

// GETTERS
TileMap * WorldMap::getCurrentMap() const
{
    return m_tileMaps[unsigned(m_currentIndexMap)];
}
