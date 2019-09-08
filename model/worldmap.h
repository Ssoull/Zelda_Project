#ifndef WORLDMAP_H
#define WORLDMAP_H

#include <vector>

#include "tilemap.h"

namespace worldmap_const {
    static const int WORLD_MAP_WIDTH = 2;
}

class WorldMap
{
private:
    std::vector<TileMap *> m_tileMaps;
    int m_currentIndexMap;

public:
    WorldMap();

    void changeMap(const char direction);

    ~WorldMap();

    // GETTERS
    TileMap *  getCurrentMap() const;
};

#endif // WORLDMAP_H
