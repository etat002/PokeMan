#include "../header/mediumLevel.h"

TEST(MediumLevel, Constructor){
	MediumLevel mediumLevel;
	EXPECT_EQ(10, mediumLevel.getExpCap());
}

TEST(MediumLevel, Raise){
	MediumLevel mediumLevel;
	mediumLevel.setExpCap();
	EXPECT_EQ(30, mediumLevel.getExpCap());
}
