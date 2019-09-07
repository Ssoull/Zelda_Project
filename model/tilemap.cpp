#include <iostream>
#include <fstream>
#include <algorithm>

#include "tilemap.h"

TileMap::TileMap() : m_tiles(TILE_MAP_WIDTH * TILE_MAP_WIDTH)
{
    int y = 0;
    for (unsigned i = 0; i < m_tiles.size(); ++i)
    {
        if (i % TILE_MAP_WIDTH == 0 && i != 0 )
        {
            ++y;
        }

        m_tiles[i] = new Tile(TileType::Tree, Coordinates(i % TILE_MAP_WIDTH, y));
    }

    m_tiles[unsigned(5 * TILE_MAP_WIDTH + 5)]->updateTileType(TileType::Herb);
    m_tiles[unsigned(4 * TILE_MAP_WIDTH + 5)]->updateTileType(TileType::Herb);
    m_tiles[unsigned(5 * TILE_MAP_WIDTH + 6)]->updateTileType(TileType::Herb);
    m_tiles[unsigned(6 * TILE_MAP_WIDTH + 5)]->updateTileType(TileType::Herb);
    m_tiles[unsigned(5 * TILE_MAP_WIDTH + 4)]->updateTileType(TileType::Herb);
}

bool TileMap::checkCollisionWithGraphicObject(const GraphicObject &graphicObject) const
{
    bool nextPositionIsWalkable = this->checkWalkableTile(graphicObject.getCoordinates()); // Upper left
    nextPositionIsWalkable = !nextPositionIsWalkable ? nextPositionIsWalkable : this->checkWalkableTile(Coordinates(graphicObject.getX() + graphicObject.getWidth() - 1, graphicObject.getY())); // Upper right
    nextPositionIsWalkable = !nextPositionIsWalkable ? nextPositionIsWalkable : this->checkWalkableTile(Coordinates(graphicObject.getX() + graphicObject.getWidth() - 1, graphicObject.getY() + graphicObject.getHeight() - 1)); // Lower right
    nextPositionIsWalkable = !nextPositionIsWalkable ? nextPositionIsWalkable : this->checkWalkableTile(Coordinates(graphicObject.getX(), graphicObject.getY() + graphicObject.getHeight() - 1)); // Lower left

    return nextPositionIsWalkable;
}

bool TileMap::checkWalkableTile(const Coordinates &coordinates) const
{
    Coordinates tileCoord(coordinates.getX() / Tile::TILE_SIZE, coordinates.getY() / Tile::TILE_SIZE);

    return m_tiles[unsigned(TILE_MAP_WIDTH * tileCoord.getY() + tileCoord.getX())]->isWalkable();
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
Tile * TileMap::getTile(const unsigned index) const
{
    return m_tiles[index];
}

unsigned TileMap::getSizeTileMap() const
{
    return unsigned(m_tiles.size());
}

bool TileMap::loadTileMap(const std::string file)
{
   std::fstream inFile(file, std::ios::in);
   if (!inFile.is_open()) {
      std::cerr << "failed to open " << file << std::endl;
      return false;
   }

   // fill buffer with content of file
   std::string str((std::istreambuf_iterator<char>(inFile)),
                   std::istreambuf_iterator<char>());

   // remove all \n char
   std :: remove_if (str.begin(), str.end() , [](const char & c) {
      return c == '\n' ;});

   unsigned int y = 0;
   for (unsigned int x = y ; x < m_tiles.size(); ++x)
   {
      if (x % TILE_MAP_WIDTH == 0 && x != 0)
      {
         ++y;
      }
      // -48 because ascii code for '0' is 48
      m_tiles[x] = new Tile((TileType)(str[x]-48), Coordinates(x % TILE_MAP_WIDTH, y));
   }
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
      if (i % TILE_MAP_WIDTH == 0)
      {
         outFile << std::endl;
      }
   }
   outFile.close();
   return true;
}

