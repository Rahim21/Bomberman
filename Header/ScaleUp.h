#ifndef SCALEUP_H
#define SCALEUP_H

#include "Item.h"

/**
 * \class ScaleUp
 * \author HAYAT Rahim / MTARFI Souhail
 */
class ScaleUp : public Item
{
protected:
public:
    /**
     * @brief Construct a new Scale Up object
     *
     * @param i
     * @param j
     * @param symbole
     */
    ScaleUp(const int i, const int j, const std::string symbole = "#");

    /**
     * @brief add more scale for the bomb
     *
     * @param b
     */
    void addScale(Bomb &b);
};

#endif