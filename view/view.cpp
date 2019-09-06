#include "view.h"

#include <iostream>

#include "model/tile.h"

View::View(Model *model, Controller *controller, QWidget *parent) :
    QGraphicsView(parent), m_model(model), m_controller(controller),
    m_scene(new QGraphicsScene(0, 0, Tile::TILE_SIZE * 11, Tile::TILE_SIZE * 11)), m_graphicalPlayer(new GraphicPlayer(controller, m_model->m_player))
{
    this->setScene(m_scene);

    m_scene->addItem(m_graphicalPlayer);
}


View::~View()
{
    delete m_graphicalPlayer;
    delete m_scene;

    std::cout << "View: Passed in the destructor" << std::endl;
}
