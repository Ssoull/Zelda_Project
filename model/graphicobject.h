#ifndef GRAPHICOBJECT_H
#define GRAPHICOBJECT_H

#include "coordinates.h"
#include "size.h"
enum Orientation{Front, Back, Left, Right};
class GraphicObject : public Coordinates, public Size
{
public:
    Orientation orientation;
    GraphicObject(const Size &size);
    GraphicObject(const Coordinates &coordinates, const Size &size);
    void setOrientation(Orientation direction);
};

#endif // GRAPHICOBJECT_H
