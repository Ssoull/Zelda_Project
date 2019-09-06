#include <QKeyEvent>
#include <iostream>

#include "graphicplayer.h"

//new GraphicObject(player->getCoordinates(), player->getSize())

GraphicPlayer::GraphicPlayer(Controller *controller, Player *player) :
    m_controller(controller), m_playerData(player),
    m_lastPoint(new Coordinates(player->getX(), player->getY()))
{
    this->setRect(m_playerData->getX(), m_playerData->getY(), m_playerData->getWidth(), m_playerData->getHeight());

    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();
}

void GraphicPlayer::keyPressEvent(QKeyEvent *event)
{
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
        std::cout << "Key not recognized" << std::endl;
        break;
    }

    int offsetOnX = m_playerData->getX() - m_lastPoint->getX();
    int offsetOnY = m_playerData->getY() - m_lastPoint->getY();
    m_lastPoint->updateCoord(m_playerData->getCoordinates());

    this->setPos(this->x() + offsetOnX, this->y() + offsetOnY);
}

GraphicPlayer::~GraphicPlayer()
{
    delete m_lastPoint;
    std::cout << "GraphicPlayer: Passed in the destructor" << std::endl;
}
