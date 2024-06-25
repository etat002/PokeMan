#ifndef _SHOCK_H_
#define _SHOCK_H_

#include "character.h"

class Shock: public Character {
public:
    Shock(double, double, double, int, LevelStrategy*);
//    ~Shock();
};

#endif
