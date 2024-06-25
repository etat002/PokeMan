#ifndef _STONE_H_
#define _STONE_H_

#include "character.h"

class Stone: public Character {
public:
    Stone(double, double, double, int, LevelStrategy*);
//    ~Stone();
};

#endif
