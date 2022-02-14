#ifndef BOMB_H
#define BOMB_H

/**
 * \class Bomb
 * \author HAYAT Rahim
 */
class Bomb
{
protected:
    int puissance;
    int portee;
    int test;
public:
    void infligerDegat();
    void afficherExplosion();
};

#endif