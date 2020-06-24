#pragma once

#include "MDFS.hpp"

#include <omp.h>
#include <vector>

class ParallelMDFS : public MDFS
{
    public:
        ParallelMDFS() : MDFS() {omp_init_lock(&writelock);}
        ParallelMDFS(int X, int Y) : MDFS(X, Y) {omp_init_lock(&writelock);}
        ~ParallelMDFS() {omp_destroy_lock(&writelock);}

        void Execute(int x, int y, int num_threads = 4);
        std::tuple<int, std::vector<std::shared_ptr<Tile>>> Worker(std::shared_ptr<Tile> tile, 
                                                  std::vector<std::shared_ptr<Tile>> localSearchVector,
                                                  std::shared_ptr<TileGraph> localTileGraph);
    private:
        omp_lock_t writelock;
};