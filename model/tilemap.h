#ifndef TILEMAP_H
#define TILEMAP_H

#include <vector>
#include <string>

#include "tile.h"
#include "character.h"

class TileMap
{
private:
    std::vector<Tile *> m_tiles;
    bool checkWalkableTile(const Coordinates &coordinates) const;
public:
    const static int TILE_MAP_WIDTH = 11;

    TileMap();

    bool checkCollisionWithGraphicObject(const GraphicObject &graphicObject) const;

    ~TileMap();

    bool loadTileMap(const std::string file);
    bool saveTileMap(const std::string file);

    // GETTERS
    Tile * getTile(const unsigned index) const;
    unsigned getSizeTileMap() const;
};

#endif // TILEMAP_H
