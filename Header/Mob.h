#ifndef MOB_H
#define MOB_H
#include <random>
#include "Position.h"
#include "Player.h"
/**
 * \class Mob
 * \author HAYAT Rahim / MTARFI Souhail
 */
class Mob : public Position
{
protected:
    int hp;
    int damage;
    float speed;

public:
    Mob();
    int Alea_sens();
    void displayObject();
    virtual void damager(Player &p) = 0;
    virtual int getMobI();
    virtual int getMobJ();
    virtual void setMobI(int _i);
    virtual void setMobJ(int _j);
    // void echanger(Map &carte, int *i2, int *j2);
    // bool verificationMouvement( Map &carte);
    // bool verification_Obstacle(Map &carte, int i2, int j2);
    // virtual void afficherMob();
};

#endif