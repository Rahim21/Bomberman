#include <iostream>
#include "Bowman.h" // linked with makefile

// Méthodes de notre classe Bowman
Bowman::Bowman(const int i, const int j, std::string symbole) : Mob{i, j, symbole}
{
    this->i = i;
    this->j = j;
    this->symbole = symbole;
}

void Bowman::damager(Player &p)
{
    if (p.heart < 5 && p.heart > 0)
    {
        p.heart -= 1;
    }
}