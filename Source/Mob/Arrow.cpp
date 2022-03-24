#include <iostream>
#include "Arrow.h"
#include "Player.h"
Arrow::Arrow(const int i, const int j, const std::string symbole):Position(i, j, symbole){
    this->i = i;
    this->j = j;
    this->symbole = symbole;
}

int Arrow::getArrowI()
{
    return i;
}

int Arrow::getArrowJ()
{
    return j;
}

void Arrow::setArrowI(int _i)
{
    this->i = _i;
}

void Arrow::setArrowJ(int _j)
{
    this->j = _j;
}
void Arrow::damager(Player &p)
{
    if (p.heart < 5 && p.heart > 0)
    {
        p.heart -= 1;
    }
}