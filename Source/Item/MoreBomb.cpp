#include <iostream>
#include "MoreBomb.h" // linked with makefile

// Méthodes de notre classe MoreBomb [augmente le nombre de bombes]
MoreBomb::MoreBomb(const int i, const int j, std::string symbole) : Item{i,j,symbole}
{
    this->i = i;
    this->j = j;
    this->symbole = symbole;
}

void MoreBomb::addBomb(Player &p)
{
    if (p.nbrBomb < 3)
    {
        p.nbrBomb += 1;
    }
}