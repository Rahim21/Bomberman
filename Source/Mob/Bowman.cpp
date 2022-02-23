#include <iostream>
#include "Bowman.h" // linked with makefile

// Méthodes de notre classe Bowman
Bowman::Bowman(const int i, const int j) : Mob{}
{
    this->i = i;
    this->j = j;
}

std::ostream &operator<<(std::ostream &os, const Bowman &b)
{
    os << "B" << std::endl;
    return os;
}