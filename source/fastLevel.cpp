#include "../header/fastLevel.h"

FastLevel::FastLevel(){
	this->capRaise = 10;
}

void FastLevel::setExpCap(){
	expCap += this->capRaise;
}
