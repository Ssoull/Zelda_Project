#include <iostream>
#include <vector>
#include <string>
#include <QDir>

#include "view.h"
#include "model/tile.h"

View::View(Model *model, Controller *controller, QWidget *parent) :
    QGraphicsView(parent), m_model(model), m_controller(controller),
    m_scene(new QGraphicsScene(0, 0, Tile::TILE_SIZE * 11, Tile::TILE_SIZE * 11)), m_graphicPlayer(new GraphicPlayer(m_model->m_player))
{
    this->setScene(m_scene);

    this->initMap();

    m_scene->addItem(m_graphicPlayer);
}

void View::keyPressEvent(QKeyEvent *event)
{
    // Note: We can separate the inputs of actions and movements
    checkMoveInput(event);
}

void View::initMap()
{
    QColor color;
    Tile *currentTile;
    QGraphicsRectItem *tile;


    m_model->m_tileMap->loadTileMap(":/data/asset/map/01.data");

    for (unsigned i = 0; i < m_model->m_tileMap->getSizeTileMap(); ++i)
    {
        currentTile = m_model->m_tileMap->getTile(i);
        tile = new QGraphicsRectItem(currentTile->getX(), currentTile->getY(), Tile::TILE_SIZE, Tile::TILE_SIZE);

        switch (m_model->m_tileMap->getTile(i)->getTileType()) {
        case TileType::Tree:
            color = Qt::darkGreen;
            break;

        case TileType::Water:
            color = Qt::cyan;
            break;

        case TileType::Herb:
            color = Qt::green;
            break;
        }

        tile->setBrush(QBrush(color));
        tile->setPen(QPen(color));
        m_scene->addItem(tile);
    }

}

void View::checkMoveInput(QKeyEvent *event)
{
    bool moveInput = true;
  /*  uint8_t keyMap[4];
    std::cerr << event->key() << " " << event-> std::endl;
    std::cerr << std::boolalpha <<  event->isAutoRepeat() << std::endl;*/
    switch(event->key())
    {
    case Qt::Key_Z:
        m_controller->manageInput('z');
        break;

    case Qt::Key_S:
        m_controller->manageInput('s');
        break;

    case Qt::Key_Q:
        m_controller->manageInput('q');
        break;

    case Qt::Key_D:
        m_controller->manageInput('d');
        break;

    default:
        std::cout << "Movement input not recognized" << std::endl;
        moveInput = false;
        break;
    }

    // Note: We avoid to update the qt item unnecessarily
    if (moveInput)
    {
        m_graphicPlayer->updateDisplay();
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
