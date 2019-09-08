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
   std::cerr << "updateDisplay(" << m_playerData->getX() << "," << m_playerData->getY() << ")"<<std::endl;
   this->setRect(m_playerData->getX(), m_playerData->getY(), m_playerData->getWidth(), m_playerData->getHeight());
}

void GraphicPlayer::resetDisplay(){
   this->setZValue(1);
   //this->setPos( this->m_playerData->getX(), this->m_playerData->getY() );
  // m_lastPoint->updateCoord(m_playerData->getCoordinates());
  // this->setRect(m_playerData->getX(), m_playerData->getY(), m_playerData->getWidth(), m_playerData->getHeight());
}


GraphicPlayer::~GraphicPlayer()
{
    if (m_lastPoint != nullptr)
    {
        delete m_lastPoint;
    }

    std::cout << "GraphicPlayer: Passed in the destructor" << std::endl;
}
