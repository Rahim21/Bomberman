#include <iostream>
#include "Grass.h" // linked with makefile

// Méthodes de notre classe Grass
Grass::Grass(const int i, const int j) : Tile{}
{
    this->i = i;
    this->j = j;
}

std::ostream
    &
    operator<<(std::ostream &os, const Grass &g)
{
    os << "" << std::endl;
    return os;
}