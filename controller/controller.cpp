#include <iostream>

#include "controller.h"

Controller::Controller(Model *model) : m_model(model)
{

}

void Controller::manageInput(char input)
{

    int newCoordX = m_model->m_player->getX();
    int newCoordY = m_model->m_player->getY();
    
    // this need to check if player was in limit with next map.
    // then if next tile was walkable.

    bool modelShouldUpdate = false;

    if(
          newCoordX <= player_const::MOVE_LIMIT_MIN ||
          newCoordX >= player_const::MOVE_LIMIT_MAX ||
          newCoordY >= player_const::MOVE_LIMIT_MAX ||
          newCoordY <= player_const::MOVE_LIMIT_MIN   )
    {
       std::cerr << "should update" << std::endl;
    }
    else {
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
    }

    if (m_model->m_tileMap->checkCollisionWithGraphicObject(GraphicObject(Coordinates(newCoordX, newCoordY), m_model->m_player->getSize())))
    {
        m_model->m_player->moveCharacter(Coordinates(newCoordX, newCoordY));
    }
}


