#include "graphicobject.h"

GraphicObject::GraphicObject(const Size &size) : Size(size), m_orientation(Orientation::Front) {}



GraphicObject::GraphicObject(const Coordinates &coordinates, const Size &size) :
    Coordinates(coordinates),
    Size(size), m_orientation(Orientation::Front)
{}

// SETTERS
void GraphicObject::setOrientation(const Orientation &direction)
{
    m_orientation = direction;
}

// GETTERS
Orientation GraphicObject::getOrientation() const
{
    return m_orientation;
}
