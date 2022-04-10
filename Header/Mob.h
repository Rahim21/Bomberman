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
    /**
     * @brief Construct a new Mob object
     *
     * @param i
     * @param j
     * @param symbole
     */
    Mob(const int i, const int j, std::string symbole);

    /**
     * @brief 50% for mob to move ont the left or right side
     *
     * @param number
     * @return int
     */
    int moveOrNote(int number);

    /**
     * @brief the mob movment follow the player
     *
     * @param pI
     * @param pJ
     * @param mI
     * @param mJ
     * @return int
     */
    int followPlayer(int pI, int pJ, int mI, int mJ);

    /**
     * @brief the mob damage the player
     *
     * @param p
     */
    virtual void damager(Player &p) = 0;

    /**
     * @brief Get the Mob I object
     *
     * @return int
     */
    virtual int getMobI();

    /**
     * @brief Get the Mob J object
     *
     * @return int
     */
    virtual int getMobJ();

    /**
     * @brief Set the Mob I object
     *
     * @param _i
     */
    virtual void setMobI(int _i);

    /**
     * @brief Set the Mob J object
     *
     * @param _j
     */
    virtual void setMobJ(int _j);

    /**
     * @brief display the mob
     *
     */
    void displayObject();

    /**
     * @brief the mob receive the bomb damage
     *
     * @param degat
     */
    void receiveBombDamage(int degat);
};

#endif