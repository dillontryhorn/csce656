#include "IterativeMDFS.hpp"
#include <atomic>
#include <iostream>

bool IterativeMDFS::Execute(int x, int y)
{
    this->searchPath.clear();
    auto startingTile = this->tilegraph->GetTile(x, y);
    
    if(startingTile != nullptr && startingTile->getID() != 2)
    {
        startingTile->setDiscovered(true);
        this->searchPath.emplace_back(startingTile);
        if(startingTile->getID() == 1) //goal node
            return true;
        auto neighbors = this->tilegraph->GetNeighbors(startingTile);
        for( auto neighbor : neighbors )
        {
            if(neighbor->getID() != 2) //don't cross into enemy node
            {
                if(IterativeMDFS::Worker(std::move(neighbor)) == 1) //goal node found
                    return true;
            }
        }
    }
    return false; //goal node not found
}

int IterativeMDFS::Worker(std::shared_ptr<Tile> tile)
{
    if(tile != nullptr)
    {
        if(!tile->isDiscovered())
        {
            tile->setDiscovered(true);
            this->searchPath.emplace_back(tile);
        }
        if(tile->getID() == 1) //goal node
            return 1;
        auto neighbors = this->tilegraph->GetNeighbors(tile);
        for(auto neighbor : neighbors)
        {
            if(neighbor->getID() != 2 && !neighbor->isDiscovered()) //don't cross into enemy node
            {
                if(Worker(neighbor) == 1) //goal node found
                    return 1;
            }
        }
    }
    return 0;
}