#include <iostream>

#include "worldmap.h"

WorldMap::WorldMap() : m_tileMaps(/*worldmap_const::WORLD_MAP_WIDTH * worldmap_const::WORLD_MAP_WIDTH*/ 2), m_currentIndexMap(0)
{
    for (unsigned int i = 0; i < m_tileMaps.size(); ++i)
    {
        m_tileMaps[i] = new TileMap(":/data/asset/map/" + std::to_string(i + 1) + ".data");
    }
}

void WorldMap::changeMap(const char direction)
{
    switch ( direction )
    {
    case 'z':
        m_currentIndexMap -= worldmap_const::WORLD_MAP_WIDTH;
        break;
    case 's':
        m_currentIndexMap += worldmap_const::WORLD_MAP_WIDTH;
        break;

    case 'q':
        --m_currentIndexMap;
        break;

    case 'd':
        ++m_currentIndexMap;
        break;

    default:
        std::cout << "Direction not recognized" << std::endl;
        break;
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
