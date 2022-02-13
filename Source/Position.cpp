#include <iostream>
#include "Position.h" // linked with makefile
#include <cmath>

// Méthodes de notre classe Position

void Position::operator+=(Position const &autre)
{
    x += autre.x;
    y += autre.y;
}

void Position::operator-=(Position const &autre)
{
    x -= autre.x;
    y -= autre.y;
}