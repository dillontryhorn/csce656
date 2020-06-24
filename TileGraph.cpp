#include "TileGraph.hpp"

#include <iostream>

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

std::vector<std::shared_ptr<Tile>> TileGraph::GetNeighbors(std::shared_ptr<Tile> tile)
{   
    std::vector<std::shared_ptr<Tile>> neighbors;
    for(auto direction : this->possible_directions)
    {
        auto neighbor = TileGraph::GetTile(tile->getX() + direction.first, tile->getY() + direction.second);
        if(neighbor != nullptr)
        {
            neighbors.emplace_back(std::move(neighbor));
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