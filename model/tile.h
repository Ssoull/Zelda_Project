#ifndef TILE_H
#define TILE_H

#include "graphicobject.h"

class Tile : public GraphicObject
{
private:
    bool walkable;
    Coordinates *m_tileCoord;

public:
    Tile(const Coordinates &tile_coord, const Size &tile_size);

    void updateTileCoord(const Coordinates &new_tile_coord);

    ~Tile();
};

#endif // TILE_H
