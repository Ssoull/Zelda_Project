#include "player.h"
#include "tilemap.h"

Player::Player() : Character(Coordinates(Tile::TILE_SIZE * (TileMap::TILE_MAP_WIDTH - 1)/2 + (Tile::TILE_SIZE - player_const::PLAYER_WIDTH)/2,
                                         Tile::TILE_SIZE * (TileMap::TILE_MAP_WIDTH - 1)/2 + (Tile::TILE_SIZE - player_const::PLAYER_WIDTH)/2),
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
