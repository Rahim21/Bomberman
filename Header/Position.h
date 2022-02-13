#ifndef POSITION_H
#define POSITION_H

/**
 * \struct Position
 * \author HAYAT Rahim
 */
struct Position
{
    float x{0.f};
    float y{0.f};
    void operator+=(Position const &autre);
    void operator-=(Position const &autre);
};

#endif
