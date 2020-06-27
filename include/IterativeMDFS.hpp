#pragma once

#include "MDFS.hpp"

class IterativeMDFS : public MDFS
{
    public:
        IterativeMDFS() : MDFS() {};
        IterativeMDFS(int X, int Y) : MDFS(X, Y) {};

        bool Execute(int x, int y);
        int Worker(std::shared_ptr<Tile> tile);
};