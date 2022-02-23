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