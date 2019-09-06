#include "tile.h"
#include <iostream>

Tile::Tile(const Coordinates &tile_coord, const Size &tile_size) :
    GraphicObject(Coordinates(tile_coord.getX() * tile_size.getWidth(), tile_coord.getX() * tile_size.getHeight()), tile_size),
    m_tileCoord(new Coordinates(tile_coord))
{

}



void Tile::updateTileCoord(const Coordinates &new_tile_coord)
{
    // We create a new Coordinates to avoid reference modification
    m_tileCoord->updateCoord(Coordinates(new_tile_coord));

    this->updateCoord(Coordinates(m_tileCoord->getX() * this->getWidth(), m_tileCoord->getY() * this->getHeight()));
}



Tile::~Tile()
{
    delete m_tileCoord;
    std::cout << "Tile: Passed in the destructor" << std::endl;
}
