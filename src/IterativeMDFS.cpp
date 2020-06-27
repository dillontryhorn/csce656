#include "IterativeMDFS.hpp"
#include <atomic>
#include <iostream>
#include <bits/stdc++.h> 

bool IterativeMDFS::Execute(int x, int y)
{
    if(this->goalTile != nullptr)
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
            std::vector<std::tuple<int, std::shared_ptr<Tile>>> hTups;
            for(auto neighbor : neighbors)
                hTups.emplace_back(neighbor->getHeuristic(), neighbor);
            std::sort(hTups.begin(), hTups.end());
            for( auto tup : hTups )
            {
                if(std::get<1>(tup)->getID() != 2) //don't cross into enemy node
                {
                    if(IterativeMDFS::Worker(std::get<1>(tup)) == 1) //goal node found
                        return true;
                }
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
        std::vector<std::tuple<int, std::shared_ptr<Tile>>> hTups;
        for(auto neighbor : neighbors)
            hTups.emplace_back(neighbor->getHeuristic(), neighbor);
        std::sort(hTups.begin(), hTups.end());
        for(auto tup : hTups)
        {
            if(std::get<1>(tup)->getID() != 2 && !std::get<1>(tup)->isDiscovered()) //don't cross into enemy node
            {
                if(Worker(std::get<1>(tup)) == 1) //goal node found
                    return 1;
            }
        }
    }
    return 0;
}