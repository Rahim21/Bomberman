#ifndef BOWMAN_H
#define BOWMAN_H

#include "Mob.h"

/**
 * \class Bowman
 * \author HAYAT Rahim / MTARFI Souhail
 */
class Bowman : public Mob
{
protected:
public:
    Bowman(const int i, const int j, const std::string symbole = "B");
    // void displayObject();
    int getMobI();
    int getMobJ();
    void setMobI(int _i);
    void setMobJ(int _j);
    void damager(Player &p);
};

#endif

// peut attaquer notre Bomberman à distance, mais pas à travers les murs