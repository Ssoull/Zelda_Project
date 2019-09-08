#include <iostream>

#include "controller.h"

Controller::Controller(Model *model) : m_model(model)
{

}

bool Controller::manageInput(char input)
{
    // this need to check if player was in limit with next map.
    bool modelShouldUpdate = this->m_model->m_player->playerCanMove();


    unsigned int newCoordX = m_model->m_player->getX();
    unsigned int newCoordY = m_model->m_player->getY();

    switch ( input )
    {
    case 'z':
        (!modelShouldUpdate ? newCoordY -= player_const::MOVE_STEP : newCoordY = player_const::MOVE_LIMIT_MAX -16);
        break;
    case 's':
        (!modelShouldUpdate ? newCoordY += player_const::MOVE_STEP : newCoordY = player_const::MOVE_LIMIT_MIN +16);
        break;

    case 'q':
        (!modelShouldUpdate ? newCoordX -= player_const::MOVE_STEP : newCoordX = player_const::MOVE_LIMIT_MAX -16);
        break;

    case 'd':
        (!modelShouldUpdate ? newCoordX += player_const::MOVE_STEP : newCoordX = player_const::MOVE_LIMIT_MIN +16);
        break;

    default:
        std::cout << "Input not recognized" << std::endl;
        break;
    }


    if(modelShouldUpdate){
        // thier check if we can move next tile
        // then invert character position.
        std::cerr << "Tile map should update." << std::endl;
        m_model->m_worldMap->changeMap(input);
        std::cerr << "test" << newCoordX << " " << newCoordY << std::endl;
    }

    // then if next tile was walkable.
    if (m_model->m_worldMap->getCurrentMap()->checkCollisionWithGraphicObject(GraphicObject(Coordinates(newCoordX, newCoordY), m_model->m_player->getSize())))
    {
        m_model->m_player->moveCharacter(Coordinates(newCoordX, newCoordY));
    }


    return modelShouldUpdate;
}


