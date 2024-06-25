#include "../header/weed.h"
#include "../header/mediumLevel.h"

TEST(Weed, Constructor) {
    Weed* test = new Weed(100, 100, 100, 2, new MediumLevel());
 
    EXPECT_EQ(test->getName(), "Weed");
    EXPECT_EQ(test->getDescription(), "This small pokeman may seem harmless, but keep your eye on it the next thing you know it'll be everywhere.  Almost impossible to get rid of.");
    EXPECT_EQ(test->getType(), grass);
    EXPECT_EQ(test->getMaxHealth(), 100);
    EXPECT_EQ(test->getHealth(), 100);
    EXPECT_EQ(test->getSpeed(), 100);
    EXPECT_EQ(test->getAttackStrength(), 100);
    EXPECT_EQ(test->getLevel(), 2);
    EXPECT_EQ(test->getExperience(), 10);
}
