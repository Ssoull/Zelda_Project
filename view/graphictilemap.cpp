#include <iostream>

#include "graphicmap.h"

GraphicTileMap::GraphicTileMap(WorldMap *world_map) : m_worldData(world_map), m_qPixmaps(5)
{
    initQPixmap();
}

void GraphicTileMap::initQPixmap()
{
    std::string name[] = {"tree", "grass", "water", "bridge", "truncate_tree"};

    for (unsigned int i = 0; i < m_qPixmaps.size(); ++i)
    {
        m_qPixmaps[i] = new QPixmap(QString::fromStdString(":/data/asset/images/" + name[i] + ".png"));
    }

}

void GraphicTileMap::clearTileMap()
{
    for(QGraphicsItem *item :  m_graphicTiles)
    {
        if (item != nullptr)
        {
            delete item;
        }
    }
    m_graphicTiles.clear();
}

void GraphicTileMap::updateTileMap(QGraphicsScene *scene)
{
    QColor color;
    TileMap *currentTileMap = m_worldData->getCurrentMap();
    Tile *currentTile;
    QGraphicsPixmapItem *tile;

    for (unsigned i = 0; i <currentTileMap->getSizeTileMap(); ++i)
    {
        currentTile = currentTileMap->getTile(i);
        if (currentTile != nullptr)
        {

            tile = new QGraphicsPixmapItem();
            tile->setPos(currentTile->getX(), currentTile->getY());

            switch (currentTileMap->getTile(i)->getTileType()) {
            case TileType::Tree:
                if (currentTile->getY() == 0)
                {
                    tile->setPixmap(*m_qPixmaps[4]);
                }
                else
                {
                    tile->setPixmap(*m_qPixmaps[TileType::Tree]);
                    tile->setPos(currentTile->getX(), currentTile->getY() - 16);
                    tile->setZValue(3);
                }
                break;

            case TileType::Water:
                tile->setPixmap(*m_qPixmaps[TileType::Water]);
                break;

            case TileType::Grass:
                tile->setPixmap(*m_qPixmaps[TileType::Grass]);
                break;

            case TileType::Wooden_Bridge:
                tile->setPixmap(*m_qPixmaps[TileType::Wooden_Bridge]);
                break;
            }

            m_graphicTiles.append(tile);
            scene->addItem(tile);
        }
        else
        {
            std::cerr << "Error current tile not found" << std::endl;
        }

    }
}

GraphicTileMap::~GraphicTileMap()
{
    for(QGraphicsItem *item :  m_graphicTiles)
    {
        if (item != nullptr)
        {
            delete item;
        }
    }

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
