#pragma once

#include "Tile.hpp"
#include <list>
#include <memory>

/*
 * The TileGraph class takes advantage of the Tile class to create a
 * tilegraph or grid with x and y coordinates. A few function help manipulate the
 * information in the tiles. Each tile is a shared pointer and lists store the pointers.
 * A sequential DFS algorithm verifies the functionality.
 * Author: Dillon Tryhorn
 */

class TileGraph
{
    public:
        TileGraph();
        TileGraph(int X, int Y);
        ~TileGraph() = default;

        std::list<std::shared_ptr<Tile>> GetNeighbors(std::shared_ptr<Tile> tile);
        void PrintNeighbors(int x, int y);

        std::shared_ptr<Tile> GetTile(int x, int y);
        
        void SetTileInfo(int x, int y, int new_x, int new_y, int id, bool discovered);
        void SetTileID(int x, int y, int new_id);
        void SetTileDiscovered(int x, int y, bool new_discovered);

        void SequentialDFS(int x, int y);
        void SequentialDFS_helper(std::shared_ptr<Tile> tile);

    private:
        std::list<std::shared_ptr<Tile>> tilegraph;
        std::list<std::pair<int, int>> possible_directions = {  std::make_pair( 0,  1),     //North
                                                                std::make_pair( 1,  0),     //East
                                                                std::make_pair( 0, -1),     //South
                                                                std::make_pair(-1,  0)  };  //West
        std::list<std::shared_ptr<Tile>> discoveredTiles;
        std::list<std::shared_ptr<Tile>> searchPath;
        int X = 0, Y = 0; //X x Y tilegraph
};