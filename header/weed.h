#ifndef _WEED_H_
#define _WEED_H_

#include "character.h"

class Weed: public Character {
public:
    Weed(double, double, double, int, LevelStrategy*);
//    ~Weed();
};

#endif
