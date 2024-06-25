#include "../header/agility.h"
#include "../header/mediumLevel.h"

TEST(Agility, Constructor) {
    Agility* test = new Agility(100, 100, 100, 2, new MediumLevel());

    EXPECT_EQ(test->getName(), "Agility");
    EXPECT_EQ(test->getDescription(), "This pokeman was born to fight.  You might be knocked out.");
    EXPECT_EQ(test->getType(), fighting);
    EXPECT_EQ(test->getMaxHealth(), 100);
    EXPECT_EQ(test->getHealth(), 100);
    EXPECT_EQ(test->getSpeed(), 100);
    EXPECT_EQ(test->getAttackStrength(), 100);
    EXPECT_EQ(test->getLevel(), 2);
    EXPECT_EQ(test->getExperience(), 10);
}
