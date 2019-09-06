#include <iostream>

#include "model.h"

Model::Model() : m_player(new Player())
{

}


Model::~Model()
{
    delete m_player;

    std::cout << "Model: Passed in the destructor" << std::endl;
}
