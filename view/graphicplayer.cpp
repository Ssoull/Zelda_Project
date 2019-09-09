#include <QBrush>
#include <QPen>
#include <iostream>

#include "graphicplayer.h"

GraphicPlayer::GraphicPlayer(Player *player) : m_playerData(player), m_lastOrientation(Orientation::NoDirection), m_qPixmaps(4)
{
    initQPixmap();

    updateDisplay();
}

void GraphicPlayer::initQPixmap()
{
    std::string name[] = {"front", "back", "left", "right"};

    for (unsigned int i = 0; i < m_qPixmaps.size(); ++i)
    {
        m_qPixmaps[i] = new QPixmap(QString::fromStdString(":/data/asset/images/link_" + name[i] + ".png"));
    }

}

void GraphicPlayer::updateDisplay()
{
    this->setPos(m_playerData->getX(), m_playerData->getY());

    if (m_lastOrientation != m_playerData->getOrientation())
    {
        switch(m_playerData->getOrientation()){
        case Orientation::Front:
            this->setPixmap(*m_qPixmaps[Orientation::Front]);
            break;

        case Orientation::Back:
            this->setPixmap(*m_qPixmaps[Orientation::Back]);
            break;

        case Orientation::Left:
            this->setPixmap(*m_qPixmaps[Orientation::Left]);
            break;

        case Orientation::Right:
            this->setPixmap(*m_qPixmaps[Orientation::Right]);
            break;

        case Orientation::NoDirection:
            break;
        }

        m_lastOrientation = m_playerData->getOrientation();
    }
}

void GraphicPlayer::resetDisplay(){
    this->setZValue(1);
    this->setPos(m_playerData->getX(), m_playerData->getY());
}

GraphicPlayer::~GraphicPlayer()
{
    for (unsigned i = 0; i < m_qPixmaps.size(); ++i)
    {
        if (m_qPixmaps[i] != nullptr)
        {
            delete m_qPixmaps[i];
        }
    }

    m_qPixmaps.clear();
    m_qPixmaps.shrink_to_fit();

    std::cout << "Graphic Player: Passed in the destructor" << std::endl;
}
