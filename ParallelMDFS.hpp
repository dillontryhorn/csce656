#pragma once

#include "MDFS.hpp"

#include <vector>

class ParallelMDFS : public MDFS
{
    public:
        ParallelMDFS() : MDFS() {};
        ParallelMDFS(int X, int Y) : MDFS(X, Y) {};

        void Execute(int x, int y, int num_threads = 4);
        std::tuple<int, std::vector<std::shared_ptr<Tile>>> Worker(std::shared_ptr<Tile> tile, 
                                                  std::vector<std::shared_ptr<Tile>> localSearchVector);
};