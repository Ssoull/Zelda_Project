#include <iostream>

#include "model.h"

Model::Model() : m_player(new Player()), m_tileMap(new TileMap())
{

}


Model::~Model()
{
    if (m_player != nullptr)
    {
        delete m_player;
    }

    if (m_tileMap != nullptr)
    {
        delete m_tileMap;
    }

    std::cout << "Model: Passed in the destructor" << std::endl;
}
