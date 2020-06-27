#include "ParallelMDFS.hpp"

#include <atomic>
#include <iostream>
#include <tuple>

std::atomic<bool> found (false);
std::atomic<int> searchPath_id (0);

bool ParallelMDFS::Execute(int x, int y)
{
    this->searchPath.clear();
    auto startingTile = this->tilegraph->GetTile(x, y);

    if(startingTile != nullptr && startingTile->getID() != 2)
    {
        startingTile->setDiscovered(true);
        this->searchPath.emplace_back(startingTile);
        if(startingTile->getID() == 1)
            return true;
        auto neighbors = this->tilegraph->GetNeighbors(startingTile);
        if(this->num_threads > neighbors.size())
            this->num_threads = neighbors.size();
        #pragma omp parallel for shared(found) num_threads(num_threads)
        for(auto it = neighbors.begin(); it < neighbors.end(); it++)
        {
            if(found) continue;
            if((*it)->getID() != 2)
            {
                auto localSP = this->SP_vector.at(searchPath_id);
                searchPath_id++;
                localSP.emplace_back(startingTile);
                if(ParallelMDFS::Worker(*it, localSP) == 1)
                    found = true;
            }
        }
    }
    if(found)
        return true;
    else
        return false;
}

int ParallelMDFS::Worker(std::shared_ptr<Tile> tile, std::vector<std::shared_ptr<Tile>> localSP)
{
    if(!tile->isDiscovered())
    {
        tile->setDiscovered(true);
        localSP.emplace_back(tile);
    }

    if(tile->getID() == 1)
    {
        this->searchPath = localSP;
        return 1;
    }

    auto neighbors = this->tilegraph->GetNeighbors(tile);
    for(auto neighbor : neighbors)
    {
        if(neighbor->getID() != 2 && !neighbor->isDiscovered())
        {
            if(ParallelMDFS::Worker(neighbor, localSP) == 1)
                return 1;
        }
    }
    return 0;
}