#ifndef MODEL_H
#define MODEL_H

#include "player.h"
#include "worldmap.h"

class Model
{
public:
    Player *m_player;

    WorldMap *m_worldMap;

    Model();

    ~Model();
};

#endif // MODEL_H
