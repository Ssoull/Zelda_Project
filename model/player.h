#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
namespace player_const {
   static const unsigned int MOVE_LIMIT_MIN = 16;
   static const unsigned int MOVE_LIMIT_MAX = 656;
}
class Player : public Character
{
public:
    const static int PLAYER_WIDTH = 32;
    const static int MOVE_STEP = 16;


    Player();

    void moveCharacter(const Coordinates &new_coord) override;
};

#endif // PLAYER_H
