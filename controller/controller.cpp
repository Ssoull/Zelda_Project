#include <iostream>

#include "controller.h"

Controller::Controller(Model *model) : m_model(model)
{

}

void Controller::manageInput(char input)
{

    int newCoordX = m_model->m_player->getX();
    int newCoordY = m_model->m_player->getY();

   std::cerr << newCoordX << " " << newCoordX%60 <<" " << newCoordY << " " << newCoordY%60 <<    m_model->m_tileMap->getSizeTileMap() << std::endl;

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
       modelShouldUpdate = true;
    }

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
    
   if (m_model->m_tileMap->checkCollisionWithGraphicObject(GraphicObject(Coordinates(newCoordX, newCoordY), m_model->m_player->getSize())))
   {
      m_model->m_player->moveCharacter(Coordinates(newCoordX, newCoordY));
   }

   if(modelShouldUpdate){
      modelShouldUpdate = false;
   }

}


