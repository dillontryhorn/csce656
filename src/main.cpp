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
    std::cout << "Invalid syntax. Proper command usage: " << name << " num_threads" << std::endl;
    exit(1);
}

int main(int argc, char* argv[])
{
    if(argc < 2)
        displayHelp(argv[0]);
    
    if(argv[0] == nullptr) {}
    
    //------------------------------------------------------------------------
    //      Iterative (Sequential) Implementation
    //------------------------------------------------------------------------
    IterativeMDFS mdfs_iterative(200, 200);

    //Enemy tiles (x, y, enemy_id = 2)
    for(int i = 1; i < 199; i++)
        mdfs_iterative.SetTileID(i, 100, 2);

    for(int i = 100; i >= 0; i--)
        mdfs_iterative.SetTileID(198, i, 2);
    std::cout << "Populated enemy tiles." << std::endl;

    //Goal tile (x, y, goal_id = 1)
    mdfs_iterative.SetGoalTile(199, 1);
    std::cout << "Populated goal tile." << std::endl;

    std::cout << "Running iterative modified depth first search" << std::endl;
    auto start = std::chrono::steady_clock::now();
    bool success = mdfs_iterative.Execute(0, 100);
    auto end = std::chrono::steady_clock::now();
    //mdfs_iterative.PrintSearchPathCoords();
    std::cout << "Iterative modified depth first search complete. Took "
              << std::chrono::duration_cast<std::chrono::microseconds>(end-start).count()
              << " microseconds. " << "Goal node found: ";
    if(success)
        std::cout << "yes";
    else
        std::cout << "no";
    std::cout << std::endl << "Search Path Size: " << mdfs_iterative.GetSearchPathSize() << std::endl << std::endl;

    //------------------------------------------------------------------------
    //      Parallel Implementation
    //------------------------------------------------------------------------
    ParallelMDFS mdfs_parallel(200, 200, atoi(argv[1])); //4 threads

    //Enemy tiles (x, y, enemy_id = 2)
    for(int i = 1; i < 199; i++)
        mdfs_parallel.SetTileID(i, 100, 2);

    for(int i = 100; i >= 0; i--)
        mdfs_parallel.SetTileID(198, i, 2);
    std::cout << "Populated enemy tiles." << std::endl;

    //Goal tile (x, y, goal_id = 1)
    mdfs_parallel.SetGoalTile(199, 1);
    std::cout << "Populated goal tile." << std::endl;

    std::cout << "Running parallel modified depth first search" << std::endl;
    start = std::chrono::steady_clock::now();
    mdfs_parallel.Execute(0, 100);
    end = std::chrono::steady_clock::now();
    //mdfs_parallel.PrintSearchPathCoords();
    std::cout << "Parallel modified depth first search complete.  Took "
              << std::chrono::duration_cast<std::chrono::microseconds>(end-start).count()
              << " microseconds. " << "Goal node found: ";
    if(success)
        std::cout << "yes";
    else
        std::cout << "no";
    std::cout << std::endl << "Search Path Size: " << mdfs_parallel.GetSearchPathSize() << std::endl << std::endl;

    return 0;
}