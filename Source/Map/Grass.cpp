#include <iostream>
#include "Grass.h" // linked with makefile

// Méthodes de notre classe Grass
Grass::Grass(const int i, const int j, std::string symbole) : Tile{i,j,symbole}
{
    this->i = i;
    this->j = j;
    this->symbole = symbole;
}