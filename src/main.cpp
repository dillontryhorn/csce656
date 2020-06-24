#include "IterativeMDFS.hpp"
#include "ParallelMDFS.hpp"

#include <chrono>
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
    
    std::cout << "Running iterative modified depth first search" << std::endl;
    IterativeMDFS mdfs_iterative;

    //Goal tile (x, y, goal_id = 1)
    mdfs_iterative.SetTileID(1, 9, 1);

    //Enemy tiles (x, y, enemy_id = 2)
    mdfs_iterative.SetTileID(1, 2, 2);
    mdfs_iterative.SetTileID(1, 8, 2);

    auto start = std::chrono::steady_clock::now();
    mdfs_iterative.Execute(0, 0);
    auto end = std::chrono::steady_clock::now();
    mdfs_iterative.PrintSearchPath();
    std::cout << "Iterative modified depth first search complete. Took "
              << std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count()
              << " nanoseconds. " << std::endl << std::endl;

    std::cout << "Running parallel modified depth first search" << std::endl;
    ParallelMDFS mdfs_parallel;

    mdfs_parallel.SetTileID(1, 9, 1);

    mdfs_parallel.SetTileID(1, 2, 2);
    mdfs_parallel.SetTileID(1, 8, 2);

    start = std::chrono::steady_clock::now();
    mdfs_parallel.Execute(0, 0);
    end = std::chrono::steady_clock::now();
    mdfs_parallel.PrintSearchPath();
    std::cout << "Parallel modified depth first search complete. Took "
              << std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count()
              << " nanoseconds. " << std::endl << std::endl;
    
    return 0;
}