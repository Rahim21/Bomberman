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
    Position(int _i, int _j, std::string symbole = "?");
    Position(int _i, int _j);
    int getI() const;
    int getJ() const;
    void operator+=(Position const &autre);
    void operator-=(Position const &autre);
    virtual void displayObject();
    virtual void receiveBombDamage(int degat);
    // nécessaire pour utiliser un opérande avec un dynamic_cast
    virtual bool isPolymorphic() noexcept { return false; }
};

#endif
