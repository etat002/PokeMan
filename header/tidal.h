#ifndef _TIDAL_H_
#define _TIDAL_H_

#include "character.h"

class Tidal: public Character {
public:
    Tidal(double, double, double, int, LevelStrategy*);
};

#endif
