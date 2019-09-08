#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"

namespace player_const {
   static const int MOVE_LIMIT_MIN = 16;
   static const int MOVE_LIMIT_MAX = 656;
   static const int PLAYER_WIDTH = 32;
   static const int MOVE_STEP = 16;
}

class Player : public Character
{
public:

    Player();

    void moveCharacter(const Coordinates &new_coord) override;
    bool playerCanMove();
};

#endif // PLAYER_H
