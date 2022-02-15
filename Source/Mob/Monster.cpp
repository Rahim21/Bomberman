#include <iostream>
#include "Monster.h" // linked with makefile

// Méthodes de notre classe Monster
std::ostream& operator<<(std::ostream& os,const Monster& m){
    os<<"M"<<std::endl;
    return os;
}