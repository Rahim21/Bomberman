#include <iostream>
#include "Mob.h" // linked with makefile

// Méthodes de notre classe Mob
Mob::Mob() : Position(i, j)
{
    hp = 100;
}
int Mob::getMobI()
{
    return i;
}

int Mob::getMobJ()
{
    return j;
}

void Mob::setMobI(int _i)
{
    this->i = _i;
}

void Mob::setMobJ(int _j)
{
    this->j = _j;
}

