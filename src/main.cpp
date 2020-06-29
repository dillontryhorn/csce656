#include "IterativeMDFS.hpp"
#include "ParallelMDFS.hpp"

#include <chrono>
#include <iostream>

/*
 * Main function to create a tilegraph
 *  and execute the search algorithms.
 * Author: Dillon Tryhorn
 */

void displayHelp(char* name)
{
    std::cout << "Invalid syntax. Proper command usage: " << name << " X Y num_threads x_goal y_goal" << std::endl;
    exit(1);
}

int main(int argc, char* argv[])
{
    if(argc < 1)
        displayHelp(argv[0]);
    
    if(argv[0] == nullptr) {}
    
    //------------------------------------------------------------------------
    //      Iterative (Sequential) Implementation
    //------------------------------------------------------------------------
    IterativeMDFS mdfs_iterative(2000, 2000);

    //Goal tile (x, y, goal_id = 1)
    mdfs_iterative.SetGoalTile(954, 384);

    //Enemy tiles (x, y, enemy_id = 2)
    mdfs_iterative.SetTileID(1, 2, 2);
    mdfs_iterative.SetTileID(1, 8, 2);

    std::cout << "Running iterative modified depth first search" << std::endl;
    auto start = std::chrono::steady_clock::now();
    bool success = mdfs_iterative.Execute(0, 0);
    auto end = std::chrono::steady_clock::now();
    //mdfs_iterative.PrintSearchPathCoords();
    std::cout << "Iterative modified depth first search complete. Took "
              << std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count()
              << " nanoseconds. " << "Goal node found: ";
    if(success)
        std::cout << "yes";
    else
        std::cout << "no";
    std::cout << std::endl << "Search Path Size: " << mdfs_iterative.GetSearchPathSize() << std::endl << std::endl;

    //------------------------------------------------------------------------
    //      Parallel Implementation
    //------------------------------------------------------------------------
    ParallelMDFS mdfs_parallel(2000, 2000, 4); //4 threads

    mdfs_parallel.SetGoalTile(954, 384);

    mdfs_parallel.SetTileID(1, 2, 2);
    mdfs_parallel.SetTileID(1, 8, 2);

    std::cout << "Running parallel modified depth first search" << std::endl;
    start = std::chrono::steady_clock::now();
    mdfs_parallel.Execute(0, 0);
    end = std::chrono::steady_clock::now();
    //mdfs_parallel.PrintSearchPathCoords();
    std::cout << "Parallel modified depth first search complete.  Took "
              << std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count()
              << " nanoseconds. " << "Goal node found: ";
    if(success)
        std::cout << "yes";
    else
        std::cout << "no";
    std::cout << std::endl << "Search Path Size: " << mdfs_parallel.GetSearchPathSize() << std::endl << std::endl;

    return 0;
}