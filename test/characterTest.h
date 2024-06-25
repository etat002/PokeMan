#include "../header/character.h"
#include "../header/slowLevel.h"
#include "../header/mediumLevel.h"
#include "../header/fastLevel.h"

TEST(Character, SetDescription_GetDescription_NonEmptyString) {
    Character* test = new Character();
    test->setDescription("information");
    EXPECT_EQ(test->getDescription(), "information");
}

TEST(Character, SetDescription_GetDescription_EmptyString) {
    Character* test = new Character();
    test->setDescription("");
    EXPECT_EQ(test->getDescription(), "");
}

TEST(Character, SetType_GetType) {
    Character* test = new Character();
    test->setType(grass);
    EXPECT_EQ(test->getType(), grass);
}

TEST(Character, SetMaxHealth_GetMaxHealth_Zero) {
    Character* test = new Character();
    test->setMaxHealth(0);
    EXPECT_EQ(test->getMaxHealth(), 0);
}

TEST(Character, SetMaxHealth_GetMaxHealth_PositiveLessThanMax) {
    Character* test = new Character();
    test->setMaxHealth(100);
    test->setMaxHealth(0);
    EXPECT_EQ(test->getMaxHealth(), 100);
}

TEST(Character, SetMaxHealth_GetMaxHealth_PositiveGreaterThanMax) {
    Character* test = new Character();
    test->setMaxHealth(2);
    EXPECT_EQ(test->getMaxHealth(), 2);
}

TEST(Character, SetMaxHealth_GetMaxHealth_Negative) {
    Character* test = new Character();
    test->setMaxHealth(-50);
    EXPECT_EQ(test->getMaxHealth(), 0);
}

TEST(Character, SetHealth_GetHealth_Zero) {
    Character* test = new Character();
    test->setHealth(0);
    EXPECT_EQ(test->getHealth(), 0);
}

TEST(Character, SetHealth_GetHealth_Positive) {
    Character* test = new Character();
    test->setMaxHealth(101);
    test->setHealth(100);
    EXPECT_EQ(test->getHealth(), 100);
}

TEST(Character, SetHealth_GetHealth_PositiveGreaterThanMax) {
    Character* test = new Character();
    test->setMaxHealth(32);
    test->setHealth(33);
    EXPECT_EQ(test->getHealth(), 32);
}

TEST(Character, SetHealth_GetHealth_Negative) {
    Character* test = new Character();
    test->setHealth(-17);
    EXPECT_EQ(test->getHealth(), 0);
}

TEST(Character, SetAttackStrength_GetAttackStrength) {
    Character* test = new Character();
    test->setAttackStrength(100);
    EXPECT_EQ(test->getAttackStrength(), 100);
}

TEST(Character, SetLevel_GetLevel_Zero) {
    Character* test = new Character();
    test->setLevel(0);
    EXPECT_EQ(test->getLevel(), 1);
    EXPECT_EQ(test->getExperience(), 0);
}

TEST(Character, SetLevel_GetLevel_Positive) {
    Character* test = new Character();
    test->setLevelUpStrategy(new SlowLevel());
    test->setLevel(100);
    EXPECT_EQ(test->getLevel(), 100);
    EXPECT_EQ(test->getLevelUpStrategy()->getExpCap(), 2980);
    EXPECT_EQ(test->getExperience(), 2950);
}

TEST(Character, SetLevel_GetLevel_PositiveLessThanOld) {
    Character* test = new Character();
    test->setLevelUpStrategy(new FastLevel());
    test->setLevel(200);
    test->setLevel(100);
    EXPECT_EQ(test->getLevel(), 200);
    EXPECT_EQ(test->getExperience(), 1990);
}

TEST(Character, SetLevel_GetLevel_Negative) {
    Character* test = new Character();
    test->setLevel(-100);
    EXPECT_EQ(test->getLevel(), 1);
    EXPECT_EQ(test->getExperience(), 0);
}

TEST(Character, SetSpeed_GetSpeed) {
    Character* test = new Character();
    test->setSpeed(100);
    EXPECT_EQ(test->getSpeed(), 100);
}

TEST(Character, SetLevelUpStrategy_GetLevelUpStrategy_Slow) {
    Character* test = new Character();
    test->setLevelUpStrategy(new SlowLevel());
    EXPECT_EQ(test->getLevelUpStrategy()->getExpCap(), 10);
}

TEST(Character, SetLevelUpStrategy_GetLevelUpStrategy_Medium) {
    Character* test = new Character();
    test->setLevelUpStrategy(new MediumLevel());
    EXPECT_EQ(test->getLevelUpStrategy()->getExpCap(), 10);
}

TEST(Character, SetLevelUpStrategy_GetLevelUpStrategy_Fast) {
    Character* test = new Character;
    test->setLevelUpStrategy(new FastLevel());
    EXPECT_EQ(test->getLevelUpStrategy()->getExpCap(), 10);
}

TEST(Character, SetLevelUpStrategy_GetLevelUpStrategy_Nullptr) {
    Character* test = new Character();
    test->setLevelUpStrategy(nullptr);
    EXPECT_EQ(test->getLevelUpStrategy()->getExpCap(), 10);
}
/*
TEST(Character, SetAttacks_GetAttacks) {
    Character* test = new Character();
    vector<AtkStrategy*> attacks;

    attacks.push_back(new AtkStrategy());
    attacks.push_back(new AtkStrategy());
    attacks.push_back(nullptr);
    attacks.push_back(nullptr);

    test->setAttacks(attacks);

    vector<AtkStrategy*> setAttacks;
    setAttacks = test->getAttacks();

    EXPECT_EQ(setAttacks[0]->getAttackName(), "Attack");
    EXPECT_EQ(setAttacks[1]->getAttackName(), "Attack");
    EXPECT_EQ(setAttacks[2], nullptr);
    EXPECT_EQ(setAttacks[3], nullptr);   
}
*/
TEST(Character, SetExperience_GetExperience_Zero) {
    Character* test = new Character();
    test->setExperience(0);
    EXPECT_EQ(test->getExperience(), 0);
}

TEST(Character, SetExperience_GetExperience_Positive) {
    Character* test = new Character();
    test->setExperience(100);
    EXPECT_EQ(test->getExperience(), 100);
    EXPECT_EQ(test->getLevelUpStrategy()->getExpCap(), 110);
    EXPECT_EQ(test->getLevel(), 6);
}

TEST(Character, SetExperience_GetExperience_PositiveLessThenOld) {
    Character* test = new Character();
    test->setExperience(100);
    test->setExperience(20);
    EXPECT_EQ(test->getExperience(), 100);
    EXPECT_EQ(test->getLevelUpStrategy()->getExpCap(), 110);
    EXPECT_EQ(test->getLevel(), 6);
}

TEST(Character, SetExperience_GetExperience_Negative) {
    Character* test = new Character();
    test->setExperience(-21);
    EXPECT_EQ(test->getExperience(), 0);
}

TEST(Character, UpdateExperience) {
    Character* test = new Character();
    test->updateExperience();
    EXPECT_EQ(test->getExperience(), 5);
}

TEST(Character, UpdateExperienceMultiple) {
    Character* test = new Character();
    test->updateExperience();
    test->updateExperience();
    test->updateExperience();
    test->updateExperience();
    EXPECT_EQ(test->getExperience(), 20);
    EXPECT_EQ(test->getLevelUpStrategy()->getExpCap(), 30);
    EXPECT_EQ(test->getLevel(), 2);
}

TEST(Character, LevelUp) {
    Character* test = new Character();
    test->levelUp();
    EXPECT_EQ(test->getLevel(), 2);
    EXPECT_EQ(test->getLevelUpStrategy()->getExpCap(), 30);
}
