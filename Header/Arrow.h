#ifndef ARROW_H
#define ARROW_H
#include "Position.h"
#include "Player.h"
/**
 * \class Arrow
 * \author HAYAT Rahim / MTARFI Souhail
 */
class Arrow:public Position
{

public:
    Arrow(const int i, const int j, const std::string symbole = "^");
    int getArrowI();
    int getArrowJ();
    void setArrowI(int _i);
    void setArrowJ(int _j);
    void damager(Player &P);
};

#endif