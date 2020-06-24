#pragma once

#include "TileGraph.hpp"

#include <memory>

/*
 * Modified Depth First Search Algorithm - Parent Class
 * Traverse a tile graph and find the goal node
 * 
 * Author: Dillon Tryhorn
 */

class MDFS
{
    public:
        MDFS();
        MDFS(int X, int Y);
        ~MDFS() = default;
        
        //virtual void Execute(int x, int y) = 0;
        //virtual int Worker(std::shared_ptr<Tile> tile) = 0;

        void SetTileInfo(int x, int y, int new_x, int new_y, int new_id, bool new_discovered);
        void SetTileID(int x, int y, int new_id);
        void SetTileDiscovered(int x, int y, bool new_discovered);

        std::vector<std::shared_ptr<Tile>> GetSearchPath();
        void PrintSearchPath();

    protected:
        std::shared_ptr<TileGraph> tilegraph;
        std::vector<std::shared_ptr<Tile>> searchPath;
};