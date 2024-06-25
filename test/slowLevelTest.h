#include "../header/slowLevel.h"

TEST(SlowLevel, Constructor){
	SlowLevel slowLevel;
	EXPECT_EQ(10, slowLevel.getExpCap());
}

TEST(SlowLevel, Raise){
	SlowLevel slowLevel;
	slowLevel.setExpCap();
	EXPECT_EQ(40, slowLevel.getExpCap());
}


