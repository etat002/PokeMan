#include "../header/slowLevel.h"

SlowLevel::SlowLevel(){
	capRaise = 30;
}

void SlowLevel::setExpCap(){
	expCap += capRaise;
}
