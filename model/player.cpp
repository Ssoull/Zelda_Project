#include "player.h"
#include "tile.h"

Player::Player() : Character(Coordinates(Tile::TILE_SIZE * 5, Tile::TILE_SIZE * 5), Size(64))
{

}

void Player::moveCharacter(const Coordinates &new_coord)
{
    this->updateCoord(new_coord);
}
