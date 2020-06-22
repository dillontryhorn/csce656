#include "tilegraph.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
    if(argc < 1)
        exit(1);
    
    if(argv[0] == nullptr) {}

    TileGraph tilegraph;

    tilegraph.SequentialDFS(0,0);
    
    return 0;
}