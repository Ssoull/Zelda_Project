#include "graphicobject.h"

GraphicObject::GraphicObject(const Size &size) : Size(size) {}



GraphicObject::GraphicObject(const Coordinates &coordinates, const Size &size) :
    Coordinates(coordinates),
    Size(size)
{
    orientation=Front;
}

void GraphicObject::setOrientation(Orientation direction){
    this->orientation = direction;
}
