#include "coordinates.h"

Coordinates::Coordinates() : m_coordX(0), m_coordY(0) {}



Coordinates::Coordinates(const int coordX, const int coordY) : m_coordX(coordX), m_coordY(coordY) {}



void Coordinates::updateCoord(const Coordinates &new_coord)
{
    m_coordX = new_coord.m_coordX;
    m_coordY = new_coord.m_coordY;
}



void Coordinates::updateCoord(const int new_coord_x, const int new_coord_y)
{
    this->updateCoord(Coordinates(new_coord_x, new_coord_y));
}


// GETTERS
Coordinates Coordinates::getCoordinates() const
{
    return Coordinates(m_coordX, m_coordY);
}

int Coordinates::getX() const
{
    return m_coordX;
}

int Coordinates::getY() const
{
    return m_coordY;
}
