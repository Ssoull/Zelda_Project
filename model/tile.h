#ifndef TILE_H
#define TILE_H

#include "graphicobject.h"

enum TileType {Tree, Herb, Water, Wooden_Bridge};

namespace tile_const {
   static const int TILE_SIZE = 64;
}

class Tile : public GraphicObject
{
private:
    bool walkable;
    TileType m_tileType;

    Coordinates *m_tileCoord;

public:
    Tile(const TileType tile_type, const Coordinates &tile_coord);

    void updateTileType(const TileType tile_type);
    void updateTileCoord(const Coordinates &new_tile_coord);

    // GETTERS
    TileType getTileType() const;
    bool isWalkable() const;

    ~Tile();
};

#endif // TILE_H
