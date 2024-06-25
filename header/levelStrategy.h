#ifndef __LevelStrategy_H__
#define __LevelStrategy_H__
#include <iostream>

class LevelStrategy{
protected:
int capRaise;
int expCap = 10;
public:
virtual ~LevelStrategy() {}
virtual void setExpCap() = 0;
int getExpCap() const;
};

#endif
