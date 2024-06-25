#include "../header/stone.h"
#include "../header/mediumLevel.h"

TEST(Stone, Constructor) {
    Stone* test = new Stone(100, 100, 100, 2, new MediumLevel());
 
    EXPECT_EQ(test->getName(), "Stone");
    EXPECT_EQ(test->getDescription(), "This simple pokeman is not the brightest.  What it lacks in smarts it makes up in strength.");
    EXPECT_EQ(test->getType(), rock);
    EXPECT_EQ(test->getMaxHealth(), 100);
    EXPECT_EQ(test->getHealth(), 100);
    EXPECT_EQ(test->getSpeed(), 100);
    EXPECT_EQ(test->getAttackStrength(), 100);
    EXPECT_EQ(test->getLevel(), 2);
    EXPECT_EQ(test->getExperience(), 10);
}
