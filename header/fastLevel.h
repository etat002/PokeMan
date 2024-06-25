#ifndef __fastLevel_h__
#define __fastLevel_h__

#include "levelStrategy.h"

class FastLevel : public LevelStrategy{
private:

public:
	FastLevel();
	virtual void setExpCap();
};

#endif
