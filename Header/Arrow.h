#ifndef ARROW_H
#define ARROW_H
#include "Position.h"
#include "Player.h"
/**
 * \class Arrow
 * \author HAYAT Rahim / MTARFI Souhail
 */
class Arrow : public Position
{

public:
    /**
     * @brief Construct a new Arrow object
     *
     * @param i
     * @param j
     * @param symbole
     */
    Arrow(const int i, const int j, const std::string symbole = "^");

    /**
     * @brief Get the Arrow I object
     *
     * @return int
     */
    int getArrowI();

    /**
     * @brief Get the Arrow J object
     *
     * @return int
     */
    int getArrowJ();

    /**
     * @brief Set the Arrow I object
     *
     * @param _i
     */
    void setArrowI(int _i);

    /**
     * @brief Set the Arrow J object
     *
     * @param _j
     */
    void setArrowJ(int _j);

    /**
     * @brief damage the player
     *
     * @param P Player
     */
    void damager(Player &P);
};

#endif