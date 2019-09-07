#ifndef TILEMAP_H
#define TILEMAP_H

#include <vector>

#include "tile.h"

class TileMap
{
private:
    std::vector<Tile *> m_tiles;
public:
    const static int TILE_MAP_WIDTH = 11;

    TileMap();

    ~TileMap();
    // GETTERS
    Tile * getTile(const unsigned index) const;
    unsigned getSizeTileMap() const;
};

#endif // TILEMAP_H
