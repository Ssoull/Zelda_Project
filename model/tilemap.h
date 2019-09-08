#ifndef TILEMAP_H
#define TILEMAP_H

#include <vector>
#include <string>

#include "tile.h"
#include "character.h"

namespace tilemap_const {
    static const int TILE_MAP_WIDTH = 11;
}

class TileMap
{
private:
    std::vector<Tile *> m_tiles;
    bool checkWalkableTile(const Coordinates &coordinates) const;
public:

    TileMap();
    TileMap(std::string file);

    bool checkCollisionWithGraphicObject(const GraphicObject &graphicObject) const;

    bool loadTileMap(const std::string file);
    bool saveTileMap(const std::string file);

    ~TileMap();

    // GETTERS
    Tile * getTile(const unsigned index) const;
    unsigned getSizeTileMap() const;
};

#endif // TILEMAP_H
