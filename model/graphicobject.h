#ifndef GRAPHICOBJECT_H
#define GRAPHICOBJECT_H

#include "coordinates.h"
#include "size.h"

enum Orientation{Front, Back, Left, Right, NoDirection};

class GraphicObject : public Coordinates, public Size
{
private:
    Orientation m_orientation;

public:
    GraphicObject(const Size &size);
    GraphicObject(const Coordinates &coordinates, const Size &size);

    // SETTERS
    void setOrientation(const Orientation &direction);

    // GETTERS
    Orientation getOrientation() const;
};

#endif // GRAPHICOBJECT_H
