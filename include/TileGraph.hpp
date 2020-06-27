#pragma once

#include "Tile.hpp"
#include <vector>
#include <memory>
#include <tuple>

/*
 * The TileGraph class takes advantage of the Tile class to create a
 * tilegraph or grid with x and y coordinates. A few function help manipulate the
 * information in the tiles. Each tile is a shared pointer and vectors store the pointers.
 * A sequential DFS algorithm verifies the functionality.
 * Author: Dillon Tryhorn
 */

class TileGraph
{
    public:
        TileGraph();
        TileGraph(int X, int Y);
        ~TileGraph() = default;

        std::vector<std::shared_ptr<Tile>> GetNeighbors(std::shared_ptr<Tile> tile);
        void PrintNeighbors(int x, int y);

        std::shared_ptr<Tile> GetTile(int x, int y);
        std::vector<std::shared_ptr<Tile>> GetAllTiles();

        int GetSizeX();
        int GetSizeY();

    private:
        std::vector<std::shared_ptr<Tile>> tilegraph;
        std::vector<std::pair<int, int>> possible_directions = {  std::make_pair( 0,  1),     //North
                                                                std::make_pair( 1,  0),     //East
                                                                std::make_pair( 0, -1),     //South
                                                                std::make_pair(-1,  0)  };  //West
        int X = 0, Y = 0; //X x Y tilegraph
};