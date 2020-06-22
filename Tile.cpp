#include "Tile.hpp"

#include <iostream>

Tile::Tile() { 
} //all values should already be initialized to 0

Tile::Tile(int x, int y)
{
    this->x = x;
    this->y = y;
} //other values initialized to 0

Tile::Tile(int x, int y, int id, bool discovered)
{
    this->x = x;
    this->y = y;
    this->id = id;
    this->discovered = discovered;
} //full customization

int Tile::getX()
{
    return this->x;
}

int Tile::getY()
{
    return this->y;
}

int Tile::getID()
{
    return this->id;
}

bool Tile::isDiscovered()
{
    return this->discovered;
}

void Tile::setCoordinate(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Tile::setID(int id)
{
    this->id = id;
}

void Tile::setDiscovered(bool discovered)
{
    this->discovered = discovered;
}

void Tile::printInfo() //print all info
{
    std::cout << "Tile Coordinate: (" << this->x << ", " << this->y << ") with ID: " 
              << this->id << " and Discovered: " << this->discovered << std::endl;
}

void Tile::printCoords() //just print x and y
{
    std::cout << "(" << this->getX() << ", " << this->getY() << ")" << std::endl;
}