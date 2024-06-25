#ifndef __randomLevel_h__
#define __randomLevel_h__

#include "levelStrategy.h"

class RandomLevel : public LevelStrategy{
private:

public:
        RandomLevel();
        virtual void setExpCap();
};

#endif

