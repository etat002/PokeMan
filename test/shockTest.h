#include "../header/shock.h"
#include "../header/mediumLevel.h"

TEST(Shock, Constructor) {
    Shock* test = new Shock(100, 100, 100, 2, new MediumLevel());
 
    EXPECT_EQ(test->getName(), "Shock");
    EXPECT_EQ(test->getDescription(), "They say if you could harness the power from this pokeman you could power a large city.  Be aware when crossing its path.");
    EXPECT_EQ(test->getType(), electric);
    EXPECT_EQ(test->getMaxHealth(), 100);
    EXPECT_EQ(test->getHealth(), 100);
    EXPECT_EQ(test->getSpeed(), 100);
    EXPECT_EQ(test->getAttackStrength(), 100);
    EXPECT_EQ(test->getLevel(), 2);
    EXPECT_EQ(test->getExperience(), 10);
}
