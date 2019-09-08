#ifndef GRAPHICPLAYER_H
#define GRAPHICPLAYER_H

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>

#include "model/player.h"

class GraphicPlayer : public QGraphicsPixmapItem
{
private:    
    GraphicObject *m_playerData;
    Coordinates *m_lastPoint;
public:
    GraphicPlayer(Player *player);

    void updateDisplay();
    void resetDisplay();
//    void updateDisplay(int x, int y);

    ~GraphicPlayer();
};

#endif // GRAPHICPLAYER_H
