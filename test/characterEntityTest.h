#include "../header/characterEntity.h"

TEST(CharacterEntity, GetName_SetName_Non_Empty_String) {
    CharacterEntity* test = new CharacterEntity();
    test->setName("name");
    EXPECT_EQ(test->getName(), "name");
}

TEST(CharacterEntity, GetName_SetName_Empty_String) {
    CharacterEntity* test = new CharacterEntity();
    test->setName("some name");
    test->setName("");
    EXPECT_EQ(test->getName(), "");
}
