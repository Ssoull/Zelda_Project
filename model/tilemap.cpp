#include <iostream>
#include <fstream>
#include <algorithm>
#include <QFile>

#include "tilemap.h"


TileMap::TileMap() : m_tiles(tilemap_const::TILE_MAP_WIDTH * tilemap_const::TILE_MAP_WIDTH) {}

TileMap::TileMap(std::string file) : m_tiles(tilemap_const::TILE_MAP_WIDTH * tilemap_const::TILE_MAP_WIDTH)
{
    loadTileMap(file);
}

bool TileMap::checkCollisionWithGraphicObject(const GraphicObject &graphicObject) const
{
    bool nextPositionIsWalkable = this->checkWalkableTile(graphicObject.getCoordinates()); // Upper left
    nextPositionIsWalkable = !nextPositionIsWalkable ? nextPositionIsWalkable : this->checkWalkableTile(Coordinates(graphicObject.getX() + unsigned(graphicObject.getWidth()) - 1, graphicObject.getY())); // Upper right
    nextPositionIsWalkable = !nextPositionIsWalkable ? nextPositionIsWalkable : this->checkWalkableTile(Coordinates(graphicObject.getX() + unsigned(graphicObject.getWidth()) - 1, graphicObject.getY() + unsigned(graphicObject.getHeight()) - 1)); // Lower right
    nextPositionIsWalkable = !nextPositionIsWalkable ? nextPositionIsWalkable : this->checkWalkableTile(Coordinates(graphicObject.getX(), graphicObject.getY() + unsigned(graphicObject.getHeight()) - 1)); // Lower left

    return nextPositionIsWalkable;
}

bool TileMap::checkWalkableTile(const Coordinates &coordinates) const
{
    Coordinates tileCoord(coordinates.getX() / tile_const::TILE_SIZE, coordinates.getY() / tile_const::TILE_SIZE);
    auto * ptr = m_tiles[unsigned(tilemap_const::TILE_MAP_WIDTH * tileCoord.getY() + tileCoord.getX())];
    return (ptr ? ptr->isWalkable() : false );
}


bool TileMap::loadTileMap(const std::string file)
{
    // new file
    QFile inFile(file.c_str());

    // open in read only
    if (!inFile.open(QIODevice::ReadOnly)) {
        std::cerr << "failed to open " << file << std::endl;
        return false;
    }

    // fill buffer with content of file
    std::string str(inFile.readAll().data());

    // remove all \n char
    std :: remove_if (str.begin(), str.end() , [](const char & c) {
        return c == '\n' || c =='\r' ;});

    unsigned int y = 0;
    for (unsigned int x = y ; x < m_tiles.size(); ++x)
    {
        if (x % tilemap_const::TILE_MAP_WIDTH == 0 && x != 0)
        {
            ++y;
        }
        // -48 because ascii code for '0' is 48
        m_tiles[x] = new Tile(TileType(str[x]-48), Coordinates(x % tilemap_const::TILE_MAP_WIDTH, y));
    }

    inFile.close();

    return true;
}

bool TileMap::saveTileMap(const std::string file)
{
    std::fstream outFile(file, std::ios::out);
    if (!outFile.is_open()) {
        std::cerr << "failed to open " << file << std::endl;
        return false;
    }
    unsigned int i = 0;
    for(auto const & tile: this->m_tiles){
        i++;
        outFile << tile->getTileType();
        if (i % tilemap_const::TILE_MAP_WIDTH == 0)
        {
            outFile << std::endl;
        }
    }
    outFile.close();
    return true;
}

TileMap::~TileMap()
{
    for (unsigned i = 0; i < m_tiles.size(); ++i)
    {
        if (m_tiles[i] != nullptr)
        {
            delete m_tiles[i];
        }
    }

    m_tiles.clear();
    m_tiles.shrink_to_fit();

    std::cout << "Tile Map: Passed in the destructor" << std::endl;
}

// GETTERS
// you need to test if nullptr ( if index not found risk of segfault)
Tile * TileMap::getTile(const unsigned index) const
{
    if (m_tiles[index] != nullptr)
    {
        return m_tiles[index];
    }

    return nullptr;
}

unsigned TileMap::getSizeTileMap() const
{
    return unsigned(m_tiles.size());
}



