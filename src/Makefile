INC=-I../include

all:  tilesearch

tilesearch:	main.cpp TileGraph.cpp Tile.cpp IterativeMDFS.cpp ParallelMDFS.cpp MDFS.cpp
	g++ -o tilesearch $(INC) main.cpp TileGraph.cpp Tile.cpp IterativeMDFS.cpp ParallelMDFS.cpp MDFS.cpp -std=c++17 -Wall -Werror -Wextra -O2 -flto -fopenmp -ggdb
clean:
	rm tilesearch