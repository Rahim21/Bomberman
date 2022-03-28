#include <iostream>
#include "Mob.h" // linked with makefile

// Méthodes de notre classe Mob
Mob::Mob(const int i, const int j, std::string symbole) : Position(i, j, symbole)
{
    hp = 100;
    this->i = i;
    this->j = j;
    this->symbole = symbole;
}

int Mob::moveOrNote(int number)
{
    auto generateurAlea = std::random_device{};
    auto generateur = std::mt19937{generateurAlea()};
    auto distrubution = std::uniform_int_distribution{0, 1};
    if (distrubution(generateur) == 0)
    {
        return number;
    }
    else
    {
        return -1;
    }
}

int Mob::followPlayer(int pI, int pJ, int mI, int mJ)
{
    if (pI < mI)
    {
        return 0;
    }
    else if (pI > mI)
    {
        return 2;
    }
    else
    {
        if (pJ < mJ)
        {
            return moveOrNote(1);
        }
        else if (pJ > mJ)
        {
            return moveOrNote(3);
        }
    }
    return -1;
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

void Mob::displayObject()
{
    std::string tmp_symbole = symbole;
    if (exploded)
    {
        symbole = char(283);
        exploded = false;
        std::cout << "  " + symbole + "  ";
        symbole = tmp_symbole;
    }
    else
    {
        if (hp > 0)
        {
            std::cout << "  " + symbole + "  ";
        }
    }
}

void Mob::receiveBombDamage(int degat)
{
    hp -= 100;
    if (hp <= 0)
    {
        destroyed = true;
    }
}