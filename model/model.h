#ifndef MODEL_H
#define MODEL_H

#include "player.h"
#include "tilemap.h"

class Model
{
public:
    Player *m_player;

    TileMap *m_tileMap;

    Model();

    ~Model();
};

#endif // MODEL_H
