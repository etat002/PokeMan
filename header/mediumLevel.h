#ifndef __mediumLevel_h__
#define __mediumLevel_h__

#include "levelStrategy.h"

class MediumLevel : public LevelStrategy{
private:

public:
	MediumLevel();
	virtual void setExpCap();
};

#endif
