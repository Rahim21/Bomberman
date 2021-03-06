#include <iostream>
#include "Position.h" // linked with makefile
#include <cmath>

// Méthodes de notre classe Position
Position::Position(const int _i = 0, const int _j = 0, const std::string _symbole) : i(_i), j(_j), symbole(_symbole)
{
    exploded = false;
    destroyed = false;
}

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

void Position::displayObject()
{
    std::string tmp = symbole;
    if (exploded)
    {
        symbole = char(176);
        exploded = false;
    }
    std::cout << "  " + symbole + "  ";
    symbole = tmp;
}

void Position::receiveBombDamage(int degat)
{
    /* Nothing there : is redefined in child class */
}