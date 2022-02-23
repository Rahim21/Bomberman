#include <iostream>
#include "Wall.h" // linked with makefile

// Méthodes de notre classe Wall
Wall::Wall(const int i, const int j) : Tile{}
{
    this->i = i;
    this->j = j;
}

std::ostream &operator<<(std::ostream &os, const Wall &w)
{
    os << "I" << std::endl;
    return os;
}