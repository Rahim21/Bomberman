#ifndef SPEEDUP_H
#define SPEEDUP_H

#include "Item.h"

/**
 * \class SpeedUp
 * \author HAYAT Rahim / MTARFI Souhail
 */
class SpeedUp : public Item
{
protected:
public:
    /**
     * @brief Construct a new Speed Up object
     *
     * @param i
     * @param j
     * @param symbole
     */
    SpeedUp(const int i, const int j, const std::string symbole = "Z");

    /**
     * @brief add more speed for the player
     *
     * @param p
     */
    void addSpeed(Player &p);
};

#endif