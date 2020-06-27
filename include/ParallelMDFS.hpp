#pragma once

#include "MDFS.hpp"

#include <omp.h>
#include <vector>

class ParallelMDFS : public MDFS
{
    public:
        ParallelMDFS() : MDFS() { SP_vector.emplace_back(*(new std::vector<std::shared_ptr<Tile>>())); }
        ParallelMDFS(unsigned int num_threads) : MDFS() {
                                                            this->num_threads = num_threads;
                                                            for(unsigned int i = 0; i < num_threads; i++)
                                                                SP_vector.emplace_back(*(new std::vector<std::shared_ptr<Tile>>()));
                                                        } 
        ParallelMDFS(int X, int Y, unsigned int num_threads) : MDFS(X, Y) { this->num_threads = num_threads;
                                                                            for(unsigned int i = 0; i < num_threads; i++)
                                                                                SP_vector.emplace_back(*(new std::vector<std::shared_ptr<Tile>>()));
                                                                          }
        ParallelMDFS(int X, int Y) : MDFS(X, Y) {}
        ~ParallelMDFS() {}

        bool Execute(int x, int y);
        int Worker(std::shared_ptr<Tile> tile, std::vector<std::shared_ptr<Tile>> localSP);
    private:
        unsigned int num_threads = 1;
        std::vector<std::vector<std::shared_ptr<Tile>>> SP_vector;

};