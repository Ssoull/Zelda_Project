#include <QBrush>
#include <QPen>
#include <iostream>

#include "graphicplayer.h"

GraphicPlayer::GraphicPlayer(Player *player) : m_playerData(player), m_lastPoint(new Coordinates(player->getX(), player->getY()))
{
    this->setRect(m_playerData->getX(), m_playerData->getY(), m_playerData->getWidth(), m_playerData->getHeight());
    this->setPen(QPen(Qt::red));
    this->setBrush(QBrush(Qt::red));

    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();
}

void GraphicPlayer::updateDisplay()
{
   int offsetOnX = m_playerData->getX() - m_lastPoint->getX();
   int offsetOnY = m_playerData->getY() - m_lastPoint->getY();

   this->updateDisplay(offsetOnX,offsetOnY);
}

void GraphicPlayer::updateDisplay(int x, int y)
{
    m_lastPoint->updateCoord(m_playerData->getCoordinates());
    this->setPos(this->x() + x, this->y() + y);
}

void GraphicPlayer::resetDisplay(){
   this->setZValue(1);
   this->setPos(0 , 0);
   updateDisplay(this->m_playerData->getX(),this->m_playerData->getY());
}


GraphicPlayer::~GraphicPlayer()
{
    if (m_lastPoint != nullptr)
    {
        delete m_lastPoint;
    }

    std::cout << "GraphicPlayer: Passed in the destructor" << std::endl;
}
