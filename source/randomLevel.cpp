#include "../header/randomLevel.h"
#include <cmath>

RandomLevel::RandomLevel(){
        srand(time(NULL));
}

void RandomLevel::setExpCap(){
	capRaise = (rand()%30) + 1;
        expCap += this->capRaise;
}

