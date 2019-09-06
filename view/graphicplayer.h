#ifndef GRAPHICPLAYER_H
#define GRAPHICPLAYER_H

#include <QGraphicsRectItem>

#include "model/player.h"

class GraphicPlayer : public QGraphicsRectItem
{
private:    
    GraphicObject *m_playerData;
    Coordinates *m_lastPoint;
public:
    GraphicPlayer(Player *player);

    void updateDisplay();

    ~GraphicPlayer();
};

#endif // GRAPHICPLAYER_H
