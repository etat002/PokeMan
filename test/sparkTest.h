#include "../header/spark.h"
#include "../header/mediumLevel.h"

TEST(Spark, Constructor) {
    Spark* test = new Spark(100, 100, 100, 2, new MediumLevel());
 
    EXPECT_EQ(test->getName(), "Spark");
    EXPECT_EQ(test->getDescription(), "It only takes a spark to start a fire.  This guy leaves flames where it goes.");
    EXPECT_EQ(test->getType(), fire);
    EXPECT_EQ(test->getMaxHealth(), 100);
    EXPECT_EQ(test->getHealth(), 100);
    EXPECT_EQ(test->getSpeed(), 100);
    EXPECT_EQ(test->getAttackStrength(), 100);
    EXPECT_EQ(test->getLevel(), 2);
    EXPECT_EQ(test->getExperience(), 10);
}
