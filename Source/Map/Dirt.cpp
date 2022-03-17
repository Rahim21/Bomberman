#include <iostream>
#include "Dirt.h" // linked with makefile

// Méthodes de notre classe Dirt
Dirt::Dirt(const int i, const int j, std::string symbole) : Tile{i,j,symbole}
{
    this->i = i;
    this->j = j;
    this->symbole = symbole;
}

void Dirt::displayObject()
{
    if (tileHP >= 2)
    {
        symbole = "W";
    }
    else if (tileHP == 1)
    {
        symbole = "w";
    }
    std::cout << "  " + symbole + "  ";
}