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

int Mob::Alea_sens()
{
    auto generateurAlea = std::random_device{};
    auto generateur = std::mt19937{generateurAlea()};
    auto distrubution = std::uniform_int_distribution{0, 3};
    return distrubution(generateur);
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

void Mob::receiveBombDamage()
{
    hp -= 100;
    if (hp <= 0)
    {
        destroyed = true;
    }
}