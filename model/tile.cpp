#include "tile.h"
#include <iostream>

Tile::Tile(const Coordinates &tile_coord, const Size &tile_size) :
   GraphicObject(Coordinates(tile_coord.m_coordX * tile_size.m_width, tile_coord.m_coordY * tile_size.m_height), tile_size),
   m_tileCoord(new Coordinates(tile_coord))
{

}



void Tile::updateTileCoord(const Coordinates &new_tile_coord)
{
    // We create a new Coordinates to avoid reference modification
    m_tileCoord->updateCoord(Coordinates(new_tile_coord));

    this->updateCoord(Coordinates(m_tileCoord->m_coordX * m_width, m_tileCoord->m_coordY * m_height));
}



Tile::~Tile()
{
    delete m_tileCoord;
    std::cout << "Tile: Passed in the destructor" << std::endl;
}
