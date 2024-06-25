#include "../header/vulture.h"
#include "../header/mediumLevel.h"

TEST(Vulture, Constructor) {
    Vulture* test = new Vulture(100, 100, 100, 2, new MediumLevel());
 
    EXPECT_EQ(test->getName(), "Vulture");
    EXPECT_EQ(test->getDescription(), "Known for feasting on its foes.  A predator of the skies and land.");
    EXPECT_EQ(test->getType(), flying);
    EXPECT_EQ(test->getMaxHealth(), 100);
    EXPECT_EQ(test->getHealth(), 100);
    EXPECT_EQ(test->getSpeed(), 100);
    EXPECT_EQ(test->getAttackStrength(), 100);
    EXPECT_EQ(test->getLevel(), 2);
    EXPECT_EQ(test->getExperience(), 10);
}
