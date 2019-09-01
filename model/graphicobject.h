#ifndef GRAPHICOBJECT_H
#define GRAPHICOBJECT_H

#include "coordinates.h"
#include "size.h"

class GraphicObject : public Coordinates, public Size
{
public:
    GraphicObject(const Size &size);
    GraphicObject(const Coordinates &coordinates, const Size &size);
};

#endif // GRAPHICOBJECT_H
