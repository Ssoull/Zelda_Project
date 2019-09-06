#ifndef CHARACTER_H
#define CHARACTER_H

#include "graphicobject.h"

class Character : public GraphicObject
{
public:
    Character(const Coordinates &coord, const Size &size);

    virtual void moveCharacter(const Coordinates &new_coord) = 0;

    virtual ~Character();
};

#endif // CHARACTER_H
