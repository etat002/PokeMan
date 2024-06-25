#include "../header/tidal.h"
#include "../header/mediumLevel.h"

TEST(Tidal, Constructor) {
    Tidal* test = new Tidal(100, 100, 100, 2, new MediumLevel());
 
    EXPECT_EQ(test->getName(), "Tidal");
    EXPECT_EQ(test->getDescription(), "You may see this pokeman miles away.  Run!  It leaves a pile of wreakage in its wake.");
    EXPECT_EQ(test->getType(), water);
    EXPECT_EQ(test->getMaxHealth(), 100);
    EXPECT_EQ(test->getHealth(), 100);
    EXPECT_EQ(test->getSpeed(), 100);
    EXPECT_EQ(test->getAttackStrength(), 100);
    EXPECT_EQ(test->getLevel(), 2);
    EXPECT_EQ(test->getExperience(), 10);
}
