#include <iostream>
#include "Wall.h" // linked with makefile

// Méthodes de notre classe Wall
Wall::Wall(const int i, const int j, std::string symbole) : Tile{}
{
    this->i = i;
    this->j = j;
    this->symbole = symbole;
}