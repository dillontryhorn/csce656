#pragma once

#include "MDFS.hpp"
#include "ThreadPool.hpp"

#include <omp.h>
#include <vector>
#include <thread>

class ParallelMDFS : public MDFS
{
    public:
        ParallelMDFS() : MDFS() {}
        ParallelMDFS(unsigned int num_threads) : MDFS() { this->num_threads = num_threads; } 
        ParallelMDFS(int X, int Y, unsigned int num_threads) : MDFS(X, Y) { this->num_threads = num_threads; }
        ParallelMDFS(int X, int Y) : MDFS(X, Y) {}
        ~ParallelMDFS() {}

        bool Execute(int x, int y);
        int Worker(std::shared_ptr<Tile> tile, std::vector<std::shared_ptr<Tile>> localSP);
    private:
        unsigned int num_threads = 1;
        ThreadPool *pool;
};