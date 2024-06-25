#ifndef __slowLevel_H__
#define __slowLevel_H__

#include "levelStrategy.h"

class SlowLevel : public LevelStrategy{
private:
	
public:
	SlowLevel();
	virtual void setExpCap();
};

#endif
