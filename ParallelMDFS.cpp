#include "ParallelMDFS.hpp"

#include <atomic>
#include <omp.h>
#include <tuple>

std::atomic<bool> found (false);

void ParallelMDFS::Execute(int x, int y, int num_threads)
{
    this->searchPath.clear();
    auto startingTile = this->tilegraph->GetTile(x, y);

    if(startingTile != nullptr)
    {
        startingTile->setDiscovered(true);
        this->searchPath.emplace_back(startingTile);
        if(startingTile->getID() == 1)
            return;

        auto neighbors = this->tilegraph->GetNeighbors(startingTile);

        #pragma omp parallel for shared(found) num_threads(num_threads)
        for(auto it = neighbors.begin(); it < neighbors.end(); it++)
        {
            if(found) continue;
            if((*it)->getID() != 2)
            {
                std::vector<std::shared_ptr<Tile>> localSearchVector;
                auto results = Worker(*it, localSearchVector);
                if(std::get<0>(results) == 1) //goal node found
                {
                    for(auto it = std::get<1>(results).begin(); it < std::get<1>(results).end(); it++)
                    {
                        this->searchPath.emplace_back(*it);
                    }
                    found = true;
                }
            }
        }
    }
}

std::tuple<int, std::vector<std::shared_ptr<Tile>>> ParallelMDFS::Worker(std::shared_ptr<Tile> tile, std::vector<std::shared_ptr<Tile>> localSearchVector)
{
    if(!tile->isDiscovered())
    {
        tile->setDiscovered(true);
        localSearchVector.emplace_back(tile);
    }
    if(tile->getID() == 1)
        return std::tuple<int, std::vector<std::shared_ptr<Tile>>>(1, localSearchVector);
    auto neighbors = this->tilegraph->GetNeighbors(tile);
    for(auto neighbor : neighbors)
    {
        if(neighbor->getID() != 2 || !neighbor->isDiscovered())
        {
            if(std::get<0>(Worker(neighbor, localSearchVector)) == 1)
                return std::tuple<int, std::vector<std::shared_ptr<Tile>>>(1, localSearchVector);
        }
    }
    return std::tuple<int, std::vector<std::shared_ptr<Tile>>>(0, localSearchVector);
}