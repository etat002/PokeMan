#include "../header/tele.h"
#include "../header/mediumLevel.h"

TEST(Tele, Constructor) {
    Tele* test = new Tele(100, 100, 100, 2, new MediumLevel());
 
    EXPECT_EQ(test->getName(), "Tele");
    EXPECT_EQ(test->getDescription(), "This pokeman knows what those around it are thinking.  An unfair advantage.");
    EXPECT_EQ(test->getType(), psychic);
    EXPECT_EQ(test->getMaxHealth(), 100);
    EXPECT_EQ(test->getHealth(), 100);
    EXPECT_EQ(test->getSpeed(), 100);
    EXPECT_EQ(test->getAttackStrength(), 100);
    EXPECT_EQ(test->getLevel(), 2);
    EXPECT_EQ(test->getExperience(), 10);
}
