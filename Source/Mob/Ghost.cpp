#include <iostream>
#include "Ghost.h" // linked with makefile

// Méthodes de notre classe Ghost
Ghost::Ghost(const int i, const int j) : Mob{}
{
    this->i = i;
    this->j = j;
}

std::ostream &operator<<(std::ostream &os, const Ghost &g)
{
    os << "G" << std::endl;
    return os;
}

int Ghost::getMobI()
{
    return i;
}

int Ghost::getMobJ()
{
    return j;
}

void Ghost::setMobI(int _i)
{
    this->i = _i;
}

void Ghost::setMobJ(int _j)
{
    this->j = _j;
}
void Ghost::damager(Player &p){
        if (p.heart < 5 && p.heart > 0)
    {
        p.heart -= 1;
    }
}