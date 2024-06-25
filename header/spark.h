#ifndef _SPARK_H_
#define _SPARK_H_

#include "character.h"

class Spark: public Character {
public:
    Spark(double, double, double, int, LevelStrategy*);
//    ~Spark();
};

#endif
