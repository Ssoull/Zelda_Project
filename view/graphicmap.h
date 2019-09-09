#ifndef GRAPHICTILEMAP_H
#define GRAPHICTILEMAP_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <vector>

#include "model/worldmap.h"

class GraphicTileMap
{
private:
    WorldMap *m_worldData;

    QList<QGraphicsItem *> m_graphicTiles;

    std::vector<QPixmap *> m_qPixmaps;

    void initQPixmap();
public:
    GraphicTileMap(WorldMap *world_map);

    void clearTileMap();
    void updateTileMap(QGraphicsScene *scene);


    ~GraphicTileMap();
};

#endif // GRAPHICTILEMAP_H
