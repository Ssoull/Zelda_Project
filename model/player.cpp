#include "player.h"
#include "tilemap.h"

Player::Player() : Character(Coordinates(Tile::TILE_SIZE * (TileMap::TILE_MAP_WIDTH - 1)/2 + (Tile::TILE_SIZE - PLAYER_WIDTH)/2,
                                         Tile::TILE_SIZE * (TileMap::TILE_MAP_WIDTH - 1)/2 + (Tile::TILE_SIZE - PLAYER_WIDTH)/2),
                             Size(PLAYER_WIDTH))
{

}

void Player::moveCharacter(const Coordinates &new_coord)
{
    this->updateCoord(new_coord);
}
