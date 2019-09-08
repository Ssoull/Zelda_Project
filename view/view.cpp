#include <iostream>
#include <vector>
#include <string>
#include <QDir>

#include "view.h"
#include "model/tile.h"

View::View(Model *model, Controller *controller, QWidget *parent) :
    QGraphicsView(parent), m_model(model), m_controller(controller),
    m_scene(new QGraphicsScene(0, 0, tile_const::TILE_SIZE * 11, tile_const::TILE_SIZE * 11)), m_graphicPlayer(new GraphicPlayer(m_model->m_player))
{
    this->setScene(m_scene);

    this->updateTilemap();

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
        this->updateTilemap();
        m_graphicPlayer->resetDisplay();
        m_graphicPlayer->updateDisplay();
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

void View::updateTilemap()
{
    QColor color;
    TileMap *currentTileMap = m_model->m_worldMap->getCurrentMap();
    Tile *currentTile;
    QGraphicsRectItem *tile;

    for (unsigned i = 0; i <currentTileMap->getSizeTileMap(); ++i)
    {
        currentTile = currentTileMap->getTile(i);
        if (currentTile != nullptr)
        {
            tile = new QGraphicsRectItem(currentTile->getX(), currentTile->getY(), tile_const::TILE_SIZE, tile_const::TILE_SIZE);

            switch (currentTileMap->getTile(i)->getTileType()) {
            case TileType::Tree:
                color = Qt::darkGreen;
                break;

            case TileType::Water:
                color = Qt::cyan;
                break;

            case TileType::Herb:
                color = Qt::green;
                break;

            case TileType::Wooden_Bridge:
                color = QColor(139,69,19);
                break;
            }

            tile->setBrush(QBrush(color));
            tile->setPen(QPen(color));
            m_scene->addItem(tile);
        }
        else
        {
            std::cerr << "Error current tile not found" << std::endl;
        }
    }
}
