#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"

class Player : public Character
{
public:
    const static int MOVE_STEP = 10;

    Player();

    void moveCharacter(const Coordinates &new_coord) override;
};

#endif // PLAYER_H
