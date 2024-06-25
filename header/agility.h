#ifndef _AGILITY_H_
#define _AGILITY_H_

#include "character.h"

class Agility: public Character {
public:
    Agility(double, double, double, int, LevelStrategy*);
    //~Agility();
};

#endif
