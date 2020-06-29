#include "MDFS.hpp"

#include <iostream>
#include <stdlib.h>

MDFS::MDFS()
{
    this->tilegraph = std::make_shared<TileGraph>();
}

MDFS::MDFS(int X, int Y)
{
    this->tilegraph = std::make_shared<TileGraph>(X, Y);
}

void MDFS::SetTileInfo(int x, int y, int new_x, int new_y, int new_id, bool new_discovered)
{
    auto tile = this->tilegraph->GetTile(x, y);
    tile->setCoordinate(new_x, new_y);
    tile->setID(new_id);
    tile->setDiscovered(new_discovered);
}

void MDFS::SetTileID(int x, int y, int new_id)
{
    auto tile = this->tilegraph->GetTile(x, y);
    tile->setID(new_id);
}

void MDFS::SetTileDiscovered(int x, int y, bool new_discovered)
{
    auto tile = this->tilegraph->GetTile(x, y);
    tile->setDiscovered(new_discovered);
}

void MDFS::SetGoalTile(int x, int y)
{
    MDFS::SetTileID(x, y, 1);
    this->goalTile = this->tilegraph->GetTile(x, y);
    for(auto tile : this->tilegraph->GetAllTiles())
    {
        tile->setHeuristic(MDFS::calculateHeuristic(tile));
    }
}

std::vector<std::shared_ptr<Tile>> MDFS::GetSearchPath()
{
    return this->searchPath;
}

int MDFS::GetSearchPathSize()
{
    return this->searchPath.size();
}

void MDFS::PrintSearchPath()
{
    for(auto tile : searchPath)
        tile->printInfo();
    std::cout << "Search path size: " << searchPath.size() << std::endl;
}

void MDFS::PrintSearchPathCoords()
{
    for(auto tile : searchPath)
        tile->printCoords();
    std::cout << "Search path size: " << searchPath.size() << std::endl;
}

int MDFS::calculateHeuristic(int x, int y)
{
    return abs(x - this->goalTile->getX()) + abs(y - this->goalTile->getY());
}

int MDFS::calculateHeuristic(std::shared_ptr<Tile> tile)
{
    return abs(tile->getX() - this->goalTile->getX()) + abs(tile->getY() - this->goalTile->getY());
}