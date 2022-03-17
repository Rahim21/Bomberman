#include <iostream>
#include "Monster.h" // linked with makefile

// Méthodes de notre classe Monster
Monster::Monster(const int i, const int j, std::string symbole) : Mob{i,j,symbole}
{
    this->i = i;
    this->j = j;
    this->symbole = symbole;
}

// void Monster::displayObject()
// {
//     std::cout << "  M  ";
// }

int Monster::getMobI()
{
    return i;
}

int Monster::getMobJ()
{
    return j;
}

void Monster::setMobI(int _i)
{
    this->i = _i;
}

void Monster::setMobJ(int _j)
{
    this->j = _j;
}
void Monster::damager(Player &p)
{
    if (p.heart < 5 && p.heart > 0)
    {
        p.heart -= 2;
    }
}