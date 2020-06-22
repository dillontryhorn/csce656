#pragma once

/*
 * A C++ Tile class created to represent tiles in a tilemap or tilegrid with x,y coordinates.
 *  The tiles are going to be used to represent the map in a graph data structure.
 *  Didn't want to use a struct.
 * Author: Dillon Tryhorn
 */

class Tile
{
    public:
        //constructors
        Tile();                                      //all values should already be initialized to 0
        Tile(int x, int y);                          //other values initialized to 0
        Tile(int x, int y, int id, bool discovered); //full customization
        ~Tile() = default;

        //getters
        int getX();
        int getY();
        int getID();
        bool isDiscovered();

        //setters
        void setCoordinate(int x, int y);
        void setID(int id);
        void setDiscovered(bool discovered);

        //displayers
        void printInfo();
        void printCoords();
    
    private: //initialized to zero
        int x = 0;
        int y = 0;
        int id = 0;     //0 - neutral, 1 - goal, 2 - enemy
        bool discovered = false;
};