#include "tilegraph.hpp"
#include <iostream>

/*
 * Main function to create a tilegraph
 *  and execute the search algorithms.
 * Author: Dillon Tryhorn
 */

int main(int argc, char* argv[])
{
    if(argc < 1)
        exit(1);
    
    if(argv[0] == nullptr) {}

    TileGraph tilegraph;

    //Goal tile (x, y, goal_id)
    tilegraph.SetTileID(1, 9, 1);   //no goal tile by default

    //Enemy tiles (x, y, enemy_id)
    tilegraph.SetTileID(0, 1, 2);   //no enemy tiles by default
    tilegraph.SetTileID(0, 4, 2);

    tilegraph.SequentialDFS(0,0);   //must not start on an enemy tile
    tilegraph.PrintSearchPath();
    
    return 0;
}