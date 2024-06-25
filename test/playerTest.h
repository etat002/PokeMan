#include "../header/player.h"
#include "../header/agility.h"
#include "../header/vulture.h"
#include "../header/tele.h"
#include "../header/anodized.h"
#include "../header/mediumLevel.h"
#include "../header/CommonSphere.hpp"

TEST(Player, SetPokeman_GetPokeman_Empty) {
    Player* test = new Player();
    vector<Character*> pokeman;
    test->setPokeman(pokeman);
    EXPECT_EQ(test->getPokeman().size(), 0);
}

TEST(Player, SetPokeman_GetPokeman_Non_Empty) {
    Player* test = new Player();
    vector<Character*> pokeman;
    pokeman.push_back(new Agility(100, 100, 100, 1, new MediumLevel()));
    test->setPokeman(pokeman);
    EXPECT_EQ(test->getPokeman(), pokeman);
}

TEST(Player, SetPokeman_getPokeman_Non_Empty_All_Three) {
    Player* test = new Player();
    vector<Character*> pokeman;
    pokeman.push_back(new Vulture(100, 100, 100, 1, new MediumLevel()));
    pokeman.push_back(new Tele(100, 100, 100, 1, new MediumLevel()));
    pokeman.push_back(new Anodized(100, 100, 100, 1, new MediumLevel()));
    test->setPokeman(pokeman);
    EXPECT_EQ(test->getPokeman(), pokeman);
}

TEST(Player, SetInventory_getInventory_Empty) {
    Player* test = new Player();
    vector<Item*> items;
    test->setInventory(items);
    EXPECT_EQ(test->getInventory(), items);
}

TEST(Player, SetInventory_GetInventory_Non_Empty) {
    Player* test = new Player();
    vector<Item*> items;
    items.push_back(new CommonSphere());
    test->setInventory(items);
    EXPECT_EQ(test->getInventory(), items);
}

TEST(Player, SetInventory_getInventory_Non_Empty_Multiple) {
   Player* test = new Player();
    vector<Item*> items;
    items.push_back(new CommonSphere());
    items.push_back(new CommonSphere());
    items.push_back(new CommonSphere());
    items.push_back(new CommonSphere());
    items.push_back(new CommonSphere());
    items.push_back(new CommonSphere());
    items.push_back(new CommonSphere());
    items.push_back(new CommonSphere());
    test->setInventory(items);
    EXPECT_EQ(test->getInventory(), items);
}

TEST(Player, AddItem_Nullptr) {
    Player* test = new Player();
    test->addItem(nullptr);
    EXPECT_EQ(test->getInventory().size(), 0);
}

TEST(Player, AddItem) {
    Player* test = new Player();
    Item* item = new CommonSphere();
    test->addItem(item);
    EXPECT_EQ(test->getInventory().at(test->getInventory().size() - 1), item);
}
