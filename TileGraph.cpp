#include "TileGraph.hpp"

#include <iostream>
#include "assert.h"

TileGraph::TileGraph()
{
    this->X = 10;
    this->Y = 10;

    for(int x = 0; x < X; x++)
    {
        for(int y = 0; y < Y; y++)
        {
            auto newTile = std::make_shared<Tile>(x, y);
            tilegraph.emplace_back(std::move(newTile));
        }
    }
    std::cout << "Default: Constructed a 10 x 10 tile grid." << std::endl;
}

TileGraph::TileGraph(int X, int Y)
{
    this->X = X;
    this->Y = Y;

    for(int x = 0; x < X; x++)
    {
        for(int y = 0; y < Y; y++)
        {
            auto newTile = std::make_shared<Tile>(x, y);
            tilegraph.emplace_back(std::move(newTile));
        }
    }
    std::cout << "Constructed a " << X << " x " << Y << " tile grid." << std::endl;
}

std::list<std::shared_ptr<Tile>> TileGraph::GetNeighbors(std::shared_ptr<Tile> tile)
{   
    std::list<std::shared_ptr<Tile>> neighbors;
    for(auto direction : this->possible_directions)
    {
        auto neighbor = TileGraph::GetTile(tile->getX() + direction.first, tile->getY() + direction.second);
        if(neighbor != nullptr)
        {
            if(neighbor->getX() >= 0 && neighbor->getX() < this->X &&
            neighbor->getY() >= 0 && neighbor->getY() < this->Y)
            {
                neighbors.emplace_back(std::move(neighbor));
            }
        }
    }
    return std::move(neighbors);
}

void TileGraph::PrintNeighbors(int x, int y)
{
    auto checkTile = std::make_shared<Tile>(x, y);
    auto neighbors = TileGraph::GetNeighbors(std::move(checkTile));
    std::cout << "Printing neighbors of coordinate (" << x << ", " << y << ")" << std::endl;
    for( auto coordinate : neighbors )
        std::cout << "(" << coordinate->getX() << ", " << coordinate->getY() << ")" << std::endl;
}

std::shared_ptr<Tile> TileGraph::GetTile(int x, int y)
{
    for (auto it = this->tilegraph.begin(); it != this->tilegraph.end(); ++it)
    {
        if((*it)->getX() == x && (*it)->getY() == y)
        {
            return (*it);
        }
    }
    return nullptr;
}

void TileGraph::SetTileInfo(int x, int y, int new_x, int new_y, int new_id, bool new_discovered)
{
    auto tile = TileGraph::GetTile(x, y);
    tile->setCoordinate(new_x, new_y);
    tile->setID(new_id);
    tile->setDiscovered(new_discovered);
}

void TileGraph::SetTileID(int x, int y, int new_id)
{
    auto tile = TileGraph::GetTile(x, y);
    tile->setID(new_id);
}

void TileGraph::SetTileDiscovered(int x, int y, bool new_discovered)
{
    auto tile = TileGraph::GetTile(x, y);
    tile->setDiscovered(new_discovered);
}

void TileGraph::SequentialDFS(int x, int y)
{
    this->searchPath.clear();
    auto startingTile = TileGraph::GetTile(x, y);
    if(startingTile != nullptr)
    {
        startingTile->setDiscovered(true);
        this->searchPath.emplace_back(startingTile);
        auto neighbors = TileGraph::GetNeighbors(startingTile);
        for( auto neighbor : neighbors )
        {
            SequentialDFS_helper(neighbor);
        }
    }
    assert(this->searchPath.size() == this->tilegraph.size());
}

void TileGraph::SequentialDFS_helper(std::shared_ptr<Tile> tile)
{
    if(!tile->isDiscovered())
    {
        tile->setDiscovered(true);
        this->searchPath.emplace_back(tile);
    }
    auto neighbors = TileGraph::GetNeighbors(tile);
    for(auto neighbor : neighbors)
    {
        if(!neighbor->isDiscovered())
            SequentialDFS_helper(neighbor);
    }
}
