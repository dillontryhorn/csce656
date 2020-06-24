all:  tilegraph

tilegraph:	main.cpp TileGraph.cpp Tile.cpp IterativeMDFS.cpp ParallelMDFS.cpp MDFS.cpp
	g++ -o tilegraph main.cpp TileGraph.cpp Tile.cpp IterativeMDFS.cpp ParallelMDFS.cpp MDFS.cpp -std=c++17 -Wall -Werror -Wextra -O2 -flto -fopenmp
clean:
	rm tilegraph