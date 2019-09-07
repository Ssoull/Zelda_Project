#include "coordinates.h"

Coordinates::Coordinates() : m_coordX(0), m_coordY(0) {}



Coordinates::Coordinates(const unsigned int coord_x, const unsigned int coord_y) : m_coordX(coord_x), m_coordY(coord_y) {}



void Coordinates::updateCoord(const Coordinates &new_coord)
{
    m_coordX = new_coord.m_coordX;
    m_coordY = new_coord.m_coordY;
}



void Coordinates::updateCoord(const unsigned int new_coord_x, const unsigned int new_coord_y)
{
    this->updateCoord(Coordinates(new_coord_x, new_coord_y));
}


// GETTERS
Coordinates Coordinates::getCoordinates() const
{
    return Coordinates(m_coordX, m_coordY);
}

unsigned int Coordinates::getX() const
{
    return m_coordX;
}

unsigned int Coordinates::getY() const
{
    return m_coordY;
}
