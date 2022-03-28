#include <iostream>
#include "Bomb.h" // linked with makefile
#include "Tile.h"
// Méthodes de notre classe Bomb
// Bomb::Bomb() : Position{i, j} {}

Bomb::Bomb(const int i, const int j, std::string symbole) : Position{i, j, symbole}
{
    this->i = i;
    this->j = j;
}

void Bomb::infligerDegat(Position &obj, int degat)
{
    /* Inflige des dégâts aux Players, Mobs, Dirt, Bomb? qui explose à son tour*/
    std::string key = obj.symbole;
    if (key == "W" || key == "w" || key == "M" || key == "G" || key == "B" || key == "P" || key == "PO" || key == "O")
    {
        obj.receiveBombDamage(degat);
    }
}

void Bomb::displayObject()
{
    if (compteARebours > 3)
    {
        symbole = "@";
    }
    else
    {
        compteARebours += 1;
        symbole = "O";
    }
    std::cout << "  " + symbole + "  ";
}

// void Bomb::setBombIJ(int i, int j)
// {
//     this->i = i;
//     this->j = j;
// }