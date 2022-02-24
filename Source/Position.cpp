#include <iostream>
#include "Position.h" // linked with makefile
#include <cmath>


// Méthodes de notre classe Position
Position::Position(const int _i = 0, const int _j = 0) : i(_i), j(_j) {}

int Position::getI() const
{
    return i;
}

int Position::getJ() const
{
    return j;
}

void Position::operator+=(Position const &autre)
{
    i += autre.i;
    j += autre.j;
}

void Position::operator-=(Position const &autre)
{
    i -= autre.i;
    j -= autre.j;
}