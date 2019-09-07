#include <iostream>

#include "controller.h"

Controller::Controller(Model *model) : m_model(model)
{

}

void Controller::manageInput(char input)
{
    int newCoordX = m_model->m_player->getX();
    int newCoordY = m_model->m_player->getY();

    switch(input)
    {
    case 'z':
        newCoordY -= Player::MOVE_STEP;
        break;

    case 's':
        newCoordY += Player::MOVE_STEP;
        break;

    case 'q':
        newCoordX -= Player::MOVE_STEP;
        break;

    case 'd':
        newCoordX += Player::MOVE_STEP;
        break;

    default:
        std::cout << "Input not recognized" << std::endl;
        break;
    }

    if (m_model->m_tileMap->checkCollisionWithGraphicObject(GraphicObject(Coordinates(newCoordX, newCoordY), m_model->m_player->getSize())))
    {
        m_model->m_player->moveCharacter(Coordinates(newCoordX, newCoordY));
    }
}


