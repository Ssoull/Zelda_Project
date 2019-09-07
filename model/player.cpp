#include "player.h"
#include "tilemap.h"

Player::Player() : Character(Coordinates(Tile::TILE_SIZE * (TileMap::TILE_MAP_WIDTH/2 - 1), Tile::TILE_SIZE * (TileMap::TILE_MAP_WIDTH/2) - 1), Size(64))
{

}

void Player::moveCharacter(const Coordinates &new_coord)
{
    this->updateCoord(new_coord);
}
