#include <iostream>
#include "Bomb.h" // linked with makefile

// Méthodes de notre classe Bomb
// Bomb::Bomb() : Position{i, j} {}

Bomb::Bomb(const int i, const int j, std::string symbole) : Position{i, j, symbole}
{
    this->i = i;
    this->j = j;
}

void Bomb::infligerDegat()
{
    /* Inflige des dégâts aux Players, Mobs, Dirt, Bomb? qui explose à son tour*/
}

void Bomb::displayObject()
{
    if (compteARebours > 3)
    {
        if (compteARebours > 4)
        {
            compteARebours = 0;
        }
        symbole = "@";
    }
    else
    {
        compteARebours += 1;
        symbole = "O";
    }
    std::cout << "  " + symbole + "  ";
}

void Bomb::setBombIJ(int i, int j)
{
    this->i = i;
    this->j = j;
}