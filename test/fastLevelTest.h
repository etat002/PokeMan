#include "../header/fastLevel.h"

TEST(FastLevel, Constructor){
	FastLevel fastLevel;
	EXPECT_EQ(10, fastLevel.getExpCap());
}

TEST(FastLevel, Raise){
	FastLevel fastLevel;
	fastLevel.setExpCap();
	EXPECT_EQ(20, fastLevel.getExpCap());
}
