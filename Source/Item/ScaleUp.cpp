#include <iostream>
#include "ScaleUp.h" // linked with makefile

// Méthodes de notre classe ScaleUp [augmente la portée des bombes]
ScaleUp::ScaleUp(const int i, const int j, std::string symbole) : Item{}
{
    this->i = i;
    this->j = j;
    this->symbole = symbole;
}

void ScaleUp::addScale(Bomb &b)
{
    b.portee += 1;
}