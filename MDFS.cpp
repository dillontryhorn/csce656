#include "MDFS.hpp"

#include <iostream>

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

std::vector<std::shared_ptr<Tile>> MDFS::GetSearchPath()
{
    return this->searchPath;
}

void MDFS::PrintSearchPath()
{
    for(auto tile : searchPath)
        tile->printInfo();
    std::cout << "Search path size: " << searchPath.size() << std::endl;
}