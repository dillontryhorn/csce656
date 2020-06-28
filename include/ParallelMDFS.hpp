#pragma once

#include "MDFS.hpp"

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
        int Worker(std::shared_ptr<Tile> tile);
    private:
        unsigned int num_threads = 1;
        std::vector<std::thread*> threadPool;
};