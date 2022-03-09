#include <iostream>
#include "Bowman.h" // linked with makefile

// Méthodes de notre classe Bowman
Bowman::Bowman(const int i, const int j) : Mob{}
{
    this->i = i;
    this->j = j;
}

void Bowman::displayObject()
{
    std::cout << "  B  ";
}

int Bowman::getMobI()
{
    return i;
}

int Bowman::getMobJ()
{
    return j;
}

void Bowman::setMobI(int _i)
{
    this->i = _i;
}

void Bowman::setMobJ(int _j)
{
    this->j = _j;
}
void Bowman::damager(Player &p)
{
    if (p.heart < 5 && p.heart > 0)
    {
        p.heart -= 1;
    }
}