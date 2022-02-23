#include <iostream>
#include "Monster.h" // linked with makefile

// Méthodes de notre classe Monster
Monster::Monster(const int i, const int j) : Mob{}
{
    this->i = i;
    this->j = j;
}

std::ostream &operator<<(std::ostream &os, const Monster &m)
{
    os << "M" << std::endl;
    return os;
}