#include <iostream>
#include "Wall.h" // linked with makefile

// Méthodes de notre classe Wall
Wall::Wall(const int i, const int j) : Tile{}
{
    this->i = i;
    this->j = j;
}

void Wall::displayObject()
{
    std::cout << "  I  ";
}