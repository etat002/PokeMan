#include "../header/anodized.h"
#include "../header/mediumLevel.h"

TEST(Anodized, Constructor) {
    Anodized* test = new Anodized(100, 100, 100, 2, new MediumLevel());
 
    EXPECT_EQ(test->getName(), "Anodized");
    EXPECT_EQ(test->getDescription(), "Pure metal.  You won't leave a dent.");
    EXPECT_EQ(test->getType(), steel);
    EXPECT_EQ(test->getMaxHealth(), 100);
    EXPECT_EQ(test->getHealth(), 100);
    EXPECT_EQ(test->getSpeed(), 100);
    EXPECT_EQ(test->getAttackStrength(), 100);
    EXPECT_EQ(test->getLevel(), 2);
    EXPECT_EQ(test->getExperience(), 10);
}
