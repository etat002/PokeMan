#include "../header/oger.h"
#include "../header/mediumLevel.h"

TEST(Oger, Constructor) {
    Oger* test = new Oger(100, 100, 100, 2, new MediumLevel());
 
    EXPECT_EQ(test->getName(), "Oger");
    EXPECT_EQ(test->getDescription(), "??.  No one cares to find out.");
    EXPECT_EQ(test->getType(), dark);
    EXPECT_EQ(test->getMaxHealth(), 100);
    EXPECT_EQ(test->getHealth(), 100);
    EXPECT_EQ(test->getSpeed(), 100);
    EXPECT_EQ(test->getAttackStrength(), 100);
    EXPECT_EQ(test->getLevel(), 2);
    EXPECT_EQ(test->getExperience(), 10);
}
