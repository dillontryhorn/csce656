all:  tilegraph

tilegraph:	main.cpp TileGraph.cpp Tile.cpp
	g++ -o tilegraph main.cpp TileGraph.cpp Tile.cpp -std=c++17 -Wall -Werror -Wextra -O2 -flto

clean:
	rm tilegraph