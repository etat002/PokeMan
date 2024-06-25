#include "../header/randomLevel.h"

TEST(RandomLevel, Constructor){
        RandomLevel randomLevel;
        EXPECT_EQ(10, randomLevel.getExpCap());
}

TEST(RandomLevel, RaiseGT){
        RandomLevel randomLevel;
	int current = randomLevel.getExpCap();
        randomLevel.setExpCap();
        EXPECT_GT(randomLevel.getExpCap(), current);
}

TEST(RandomLevel, RaiseLT){
	RandomLevel randomLevel;
	int current = randomLevel.getExpCap();
	randomLevel.setExpCap();
	EXPECT_LT(randomLevel.getExpCap(), current+31);
}

