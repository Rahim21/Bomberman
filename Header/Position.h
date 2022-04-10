#ifndef POSITION_H
#define POSITION_H
#include <string>
/**
 * \class Position
 * \author HAYAT Rahim / MTARFI Souhail
 */
class Position
{
public:
    std::string symbole{"?"};
    int i{0};
    int j{0};
    bool exploded{false};
    bool destroyed{false};

public:
    /**
     * @brief Construct a new Position object
     *
     * @param _i
     * @param _j
     * @param symbole
     */
    Position(int _i, int _j, std::string symbole = "?");

    /**
     * @brief Construct a new Position object
     *
     * @param _i
     * @param _j
     */
    Position(int _i, int _j);

    /**
     * @brief
     *
     * @return int
     */
    int getI() const;

    /**
     * @brief
     *
     * @return int
     */
    int getJ() const;

    /**
     * @brief add position
     *
     * @param autre
     */
    void operator+=(Position const &autre);

    /**
     * @brief remove position
     *
     * @param autre
     */
    void operator-=(Position const &autre);

    /**
     * @brief display the object with this position
     *
     */
    virtual void displayObject();

    /**
     * @brief this position object reveive damage
     *
     * @param degat
     */
    virtual void receiveBombDamage(int degat);

    /**
     * @brief necessary for using dynamic_cast operand
     *
     * @return true
     * @return false
     */
    virtual bool isPolymorphic() noexcept { return false; }
};

#endif
