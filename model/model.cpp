#include <iostream>

#include "model.h"

Model::Model() : m_player(new Player()), m_worldMap(new WorldMap())
{

}


Model::~Model()
{
    if (m_player != nullptr)
    {
        delete m_player;
    }

    if (m_worldMap != nullptr)
    {
        delete m_worldMap;
    }

    std::cout << "Model: Passed in the destructor" << std::endl;
}
