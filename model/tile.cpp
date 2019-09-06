#include "tile.h"
#include <iostream>

//Tile::Tile(const TileType tileType, const Coordinates &tile_coord, const Size &tile_size) :
//    GraphicObject(Coordinates(tile_coord.getX() * tile_size.getWidth(), tile_coord.getX() * tile_size.getHeight()), tile_size),
//    m_tileCoord(new Coordinates(tile_coord))
//{

//}

Tile::Tile(const TileType tile_type, const Coordinates &tile_coord) :
    GraphicObject(Coordinates(tile_coord.getX() * TILE_SIZE, tile_coord.getX() * TILE_SIZE), Size(TILE_SIZE)),
    m_tileType(tile_type),
    m_tileCoord(new Coordinates(tile_coord))
{
    switch(m_tileType)
    {
    case TileType::Tree:
    case TileType::Water:
        walkable = false;
        break;

    case TileType::Herb:
        walkable = true;
        break;
    }
}



void Tile::updateTileCoord(const Coordinates &new_tile_coord)
{
    // We create a new Coordinates to avoid reference modification
    m_tileCoord->updateCoord(Coordinates(new_tile_coord));

    this->updateCoord(Coordinates(m_tileCoord->getX() * this->getWidth(), m_tileCoord->getY() * this->getHeight()));
}



Tile::~Tile()
{
    if (m_tileCoord != nullptr)
    {
        delete m_tileCoord;
    }

    std::cout << "Tile: Passed in the destructor" << std::endl;
}
