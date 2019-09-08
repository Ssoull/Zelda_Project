#include "player.h"
#include "tilemap.h"

Player::Player() : Character(Coordinates(tile_const::TILE_SIZE * (tilemap_const::TILE_MAP_WIDTH - 1)/2 + (tile_const::TILE_SIZE - player_const::PLAYER_WIDTH)/2,
                                         tile_const::TILE_SIZE * (tilemap_const::TILE_MAP_WIDTH - 1)/2 + (tile_const::TILE_SIZE - player_const::PLAYER_WIDTH)/2),
                             Size(player_const::PLAYER_WIDTH))
{

}

void Player::moveCharacter(const Coordinates &new_coord)
{
    this->updateCoord(new_coord);
}

bool Player::playerCanMove()
{
   return (
         this->getX() <= player_const::MOVE_LIMIT_MIN ||
         this->getX() >= player_const::MOVE_LIMIT_MAX ||
         this->getY() >= player_const::MOVE_LIMIT_MAX ||
         this->getY() <= player_const::MOVE_LIMIT_MIN   );

}
