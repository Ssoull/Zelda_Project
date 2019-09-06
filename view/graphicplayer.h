#ifndef GRAPHICPLAYER_H
#define GRAPHICPLAYER_H

#include <QGraphicsRectItem>

#include "controller/controller.h"
#include "model/player.h"

class GraphicPlayer : public QGraphicsRectItem
{
private:    
    Controller *m_controller;

    GraphicObject *m_playerData;
    Coordinates *m_lastPoint;
public:
    GraphicPlayer(Controller *controller, Player *player);

    void keyPressEvent(QKeyEvent *event);

    ~GraphicPlayer();
};

#endif // GRAPHICPLAYER_H
