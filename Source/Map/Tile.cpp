#include <iostream>
#include "Tile.h" // linked with makefile

// Méthodes de notre classe Tile [= une case de notre map]
Tile::Tile(const int i, const int j, std::string symbole) : Position(i, j, symbole) {
    this->i = i;
    this->j = j;
    this->symbole = symbole;
}