#ifndef POWERUP_H
#define POWERUP_H

#include "Item.h"

/**
 * \class PowerUp
 * \author HAYAT Rahim / MTARFI Souhail
 */
class PowerUp : public Item
{
protected:
public:
    /**
     * @brief Construct a new Power Up object
     *
     * @param i
     * @param j
     * @param symbole
     */
    PowerUp(const int i, const int j, const std::string symbole = "U");

    /**
     * @briefadd more power to the bomb
     *
     * @param b
     */
    void addPower(Bomb &b);
};

#endif