#include "../header/mediumLevel.h"

MediumLevel::MediumLevel(){
	capRaise = 20;
}

void MediumLevel::setExpCap(){
	expCap += capRaise;
}
