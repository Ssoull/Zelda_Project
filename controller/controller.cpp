#include <iostream>

#include "controller.h"

Controller::Controller(Model *model) : m_model(model)
{

}

void Controller::manageInput(char input)
{
   // this need to check if player was in limit with next map.
    bool modelShouldUpdate = this->m_model->m_player->playerCanMove();

   int newCoordX = m_model->m_player->getX();
   int newCoordY = m_model->m_player->getY();

    switch ( input )
    {
       case 'z':
          (!modelShouldUpdate ? newCoordY -= Player::MOVE_STEP : newCoordY += Player::MOVE_STEP);
          break;
       case 's':
          (!modelShouldUpdate ? newCoordY += Player::MOVE_STEP : newCoordY -= Player::MOVE_STEP);
          break;

       case 'q':
          (!modelShouldUpdate ? newCoordX -= Player::MOVE_STEP : newCoordX += Player::MOVE_STEP);
          break;

       case 'd':
          (!modelShouldUpdate ? newCoordX += Player::MOVE_STEP : newCoordX -= Player::MOVE_STEP);
          break;

       default:
          std::cout << "Input not recognized" << std::endl;
          break;
   }

   // then if next tile was walkable.
   if (m_model->m_tileMap->checkCollisionWithGraphicObject(GraphicObject(Coordinates(newCoordX, newCoordY), m_model->m_player->getSize())))
   {
      m_model->m_player->moveCharacter(Coordinates(newCoordX, newCoordY));
   }

   if(modelShouldUpdate){
      std::cerr << "Tile map should update." << std::endl;
      modelShouldUpdate = false;
   }

}


