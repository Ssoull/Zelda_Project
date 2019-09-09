#ifndef GRAPHICPLAYER_H
#define GRAPHICPLAYER_H

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <vector>

#include "model/player.h"

class GraphicPlayer : public QGraphicsPixmapItem
{
private:    
    GraphicObject *m_playerData;
    Orientation m_lastOrientation;

    std::vector<QPixmap *> m_qPixmaps;

    void initQPixmap();
public:
    GraphicPlayer(Player *player);

    void updateDisplay();
    void resetDisplay();

    ~GraphicPlayer();
};

#endif // GRAPHICPLAYER_H
