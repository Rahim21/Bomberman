#ifndef POSITION_H
#define POSITION_H

/**
 * \class Position
 * \author HAYAT Rahim / MTARFI Souhail
 */
class Position
{
protected:
    int i{0};
    int j{0};

public:
    Position(int _i, int _j);
    int getI() const;
    int getJ() const;
    void operator+=(Position const &autre);
    void operator-=(Position const &autre);
    virtual void displayObject();
    // nécessaire pour utiliser un opérande avec un dynamic_cast
    virtual bool isPolymorphic() noexcept
    {
        return false;
    }
};

#endif
