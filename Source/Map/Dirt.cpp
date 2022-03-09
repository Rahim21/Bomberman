#include <iostream>
#include "Dirt.h" // linked with makefile

// Méthodes de notre classe Dirt
Dirt::Dirt(const int i, const int j) : Tile{}
{
    this->i = i;
    this->j = j;
}

void Dirt::displayObject()
{
    if (tileHP >= 2)
    {
        std::cout << "  W  ";
    }
    else if (tileHP == 1)
    {
        std::cout << "  w  ";
    }
}