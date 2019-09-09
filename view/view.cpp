#include <iostream>
#include <vector>
#include <string>
#include <QGraphicsPixmapItem>
#include <QtAlgorithms>
#include <QDir>

#include "view.h"
#include "model/tile.h"

View::View(Model *model, Controller *controller, QWidget *parent) :
    QGraphicsView(parent), m_model(model), m_controller(controller),
    m_scene(new QGraphicsScene(0, 0, tile_const::TILE_SIZE * 11, tile_const::TILE_SIZE * 11)),
    m_graphicPlayer(new GraphicPlayer(m_model->m_player)),
    m_graphicMap(new GraphicTileMap(m_model->m_worldMap))
{
    this->setScene(m_scene);

    m_graphicMap->updateTileMap(m_scene);

    m_scene->addItem(m_graphicPlayer);
}

void View::keyPressEvent(QKeyEvent *event)
{
    // Note: We can separate the inputs of actions and movements
    checkMoveInput(event);
}

void View::checkMoveInput(QKeyEvent *event)
{
    bool moveInput = true;
    bool tileMapShouldUpdate = false;

    switch(event->key())
    {
    case Qt::Key_Z:
        tileMapShouldUpdate = m_controller->manageInput('z');
        break;

    case Qt::Key_S:
        tileMapShouldUpdate = m_controller->manageInput('s');
        break;

    case Qt::Key_Q:
        tileMapShouldUpdate = m_controller->manageInput('q');
        break;

    case Qt::Key_D:
        tileMapShouldUpdate = m_controller->manageInput('d');
        break;

    default:
        std::cout << "Movement input not recognized" << std::endl;
        moveInput = false;
        break;
    }

    // Note: We avoid to update the qt item unnecessarily
    if(tileMapShouldUpdate)
    {
        m_graphicMap->clearTileMap();
        m_graphicMap->updateTileMap(m_scene);

        m_graphicPlayer->resetDisplay();
    }
    else
    {
        if ( moveInput )
        {
            m_graphicPlayer->updateDisplay();
        }
    }
}

View::~View()
{
    if (m_graphicPlayer != nullptr)
    {
        delete m_graphicPlayer;
    }

    if (m_scene != nullptr)
    {
        delete m_scene;
    }

    std::cout << "View: Passed in the destructor" << std::endl;
}

