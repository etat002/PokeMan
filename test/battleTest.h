#include "../header/battle.h"
#include "../header/agility.h"
#include "../header/anodized.h"
#include "../header/spark.h"
#include "../header/shock.h"
#include "../header/tele.h"
#include "../header/stone.h"
#include "../header/vulture.h"
#include "../header/oger.h"
#include "../header/weed.h"
#include "../header/tidal.h"
#include "../header/player.h"
#include "../header/pokehub.h"
#include "../header/CommonSphere.hpp"
#include "../header/SmallPotion.hpp"

TEST(Battle, PlayerInput) {
    Agility* pokeman2 = new Agility(100, 100, 100, 1, new MediumLevel());
    Agility* pokeman3 = new Agility(1200, 100, 100, 1, new MediumLevel());
    Player* player = new Player();
    Pokehub* place = new Pokehub();
            
    Battle* battle = new Battle(pokeman2, pokeman3, player, true, place);
    stringstream out;
    istringstream in;
    in.str("2\n");
    battle->playerInput(in, out);
    EXPECT_EQ(out.str(), "Choose an attack 1-4 or enter 5 to check inventory:\n");
    EXPECT_EQ(pokeman3->getHealth(), 1180);
}

TEST(Battle, PlayerInputInputNotCorrect) {
    Agility* pokeman2 = new Agility(100, 100, 100, 1, new MediumLevel());
    Agility* pokeman3 = new Agility(1200, 100, 100, 1, new MediumLevel());
    Player* player = new Player();
    Pokehub* place = new Pokehub();
            
    Battle* battle = new Battle(pokeman2, pokeman3, player, true, place);
    stringstream out;
    istringstream in;
    in.str("7\n2\n");
    battle->playerInput(in, out);
    EXPECT_EQ(out.str(), "Choose an attack 1-4 or enter 5 to check inventory:\nPlease input a valid response.\n");
    EXPECT_EQ(pokeman3->getHealth(), 1180);
}

TEST(Battle, DetermineDamage) {
    Agility* pokeman2 = new Agility(100, 100, 100, 1, new MediumLevel());
    Agility* pokeman3 = new Agility(0, 100, 100, 1, new MediumLevel());
    Player* player = new Player();
    Pokehub* place = new Pokehub();

    Battle* battle = new Battle(pokeman2, pokeman3, player, true, place);
    double test = battle->determineDamage(pokeman2, pokeman3, 1);
    EXPECT_EQ(test, 20);
}

TEST(Battle, DistributeDamage) {
    Agility* pokeman2 = new Agility(100, 100, 100, 1, new MediumLevel());
    Agility* pokeman3 = new Agility(0, 100, 100, 1, new MediumLevel());
    Player* player = new Player();
    Pokehub* place = new Pokehub();

    Battle* battle = new Battle(pokeman2, pokeman3, player, true, place);
    battle->distributeDamage(pokeman2, 20);
    EXPECT_EQ(pokeman2->getHealth(), 80);
}

TEST(Battle, OutputToConsole) {
    Agility* pokeman2 = new Agility(100, 100, 100, 1, new MediumLevel());
    Agility* pokeman3 = new Agility(0, 100, 100, 1, new MediumLevel());
    Player* player = new Player();
    Pokehub* place = new Pokehub();
            
    Battle* battle = new Battle(pokeman2, pokeman3, player, true, place);
    stringstream out;
    battle->outputToConsole(out);
    EXPECT_EQ(out.str(), "\nAgility 100 health.\nAgility 0 health.\n\n    1. Fighting Punch 60 health.\n    2. Kick 20 health.\n    3. Tackle 20 health.\n    4. Scratch 20 health.\n");
}

TEST(Battle, IsOverTrue) {
    Agility* pokeman2 = new Agility(0, 100, 100, 1, new MediumLevel());
    Agility* pokeman3 = new Agility(0, 100, 100, 1, new MediumLevel());
    Player* player = new Player();
    Pokehub* place = new Pokehub();

    Battle* battle = new Battle(pokeman2, pokeman3, player, true, place);
    EXPECT_EQ(battle->isOver(), true);
}

TEST(Battle, IsOverTrue2) {
    Agility* pokeman2 = new Agility(100, 100, 100, 1, new MediumLevel());
    Agility* pokeman3 = new Agility(0, 100, 100, 1, new MediumLevel());
    Player* player = new Player();
    Pokehub* place = new Pokehub();
            
    Battle* battle = new Battle(pokeman2, pokeman3, player, true, place);
    EXPECT_EQ(battle->isOver(), true);
}

TEST(Battle, IsOverTrue3) {
    Agility* pokeman2 = new Agility(100, 100, 100, 1, new MediumLevel());
    Agility* pokeman3 = new Agility(0, 100, 100, 1, new MediumLevel());
    Player* player = new Player();
    Pokehub* place = new Pokehub();
     
    Battle* battle = new Battle(pokeman2, pokeman3, player, true, place);
    EXPECT_EQ(battle->isOver(), true);
}

TEST(Battle, IsOverFalse) {
    Agility* pokeman2 = new Agility(100, 100, 100, 1, new MediumLevel());
    Agility* pokeman3 = new Agility(100, 100, 100, 1, new MediumLevel());
    Player* player = new Player();
    Pokehub* place = new Pokehub();
            
    Battle* battle = new Battle(pokeman2, pokeman3, player, true, place);
    EXPECT_EQ(battle->isOver(), false);
}

TEST(Battle, GetIndexFire) {
    Spark* pokeman2 = new Spark(100, 100, 100, 1, new MediumLevel());
    Agility* pokeman3 = new Agility(100, 100, 100, 1, new MediumLevel());
    Player* player = new Player();
    Pokehub* place = new Pokehub();
            
    Battle* battle = new Battle(pokeman2, pokeman3, player, true, place);
    EXPECT_EQ(battle->getIndex(pokeman2), 0);
}

TEST(Battle, GetIndexGrass) {
    Weed* pokeman2 = new Weed(100, 100, 100, 1, new MediumLevel());
    Agility* pokeman3 = new Agility(0, 100, 100, 1, new MediumLevel());
    Player* player = new Player();
    Pokehub* place = new Pokehub();
            
    Battle* battle = new Battle(pokeman2, pokeman3, player, true, place);
    EXPECT_EQ(battle->getIndex(pokeman2), 1);
}

TEST(Battle, GetIndexWater) {
    Tidal* pokeman2 = new Tidal(100, 100, 100, 1, new MediumLevel());
    Agility* pokeman3 = new Agility(0, 100, 100, 1, new MediumLevel());
    Player* player = new Player();
    Pokehub* place = new Pokehub();
            
    Battle* battle = new Battle(pokeman2, pokeman3, player, true, place);
    EXPECT_EQ(battle->getIndex(pokeman2), 2);
}

TEST(Battle, GetIndexElectric) {
    Shock* pokeman2 = new Shock(100, 100, 100, 1, new MediumLevel());
    Agility* pokeman3 = new Agility(0, 100, 100, 1, new MediumLevel());
    Player* player = new Player();
    Pokehub* place = new Pokehub();
            
    Battle* battle = new Battle(pokeman2, pokeman3, player, true, place);
    EXPECT_EQ(battle->getIndex(pokeman2), 3);
}

TEST(Battle, GetIndexRock) {
    Stone* pokeman2 = new Stone(100, 100, 100, 1, new MediumLevel());
    Agility* pokeman3 = new Agility(0, 100, 100, 1, new MediumLevel());
    Player* player = new Player();
    Pokehub* place = new Pokehub();
            
    Battle* battle = new Battle(pokeman2, pokeman3, player, true, place);
    EXPECT_EQ(battle->getIndex(pokeman2), 4);
}

TEST(Battle, GetIndexFighting) {
    Agility* pokeman2 = new Agility(100, 100, 100, 1, new MediumLevel());
    Agility* pokeman3 = new Agility(0, 100, 100, 1, new MediumLevel());
    Player* player = new Player();
    Pokehub* place = new Pokehub();
            
    Battle* battle = new Battle(pokeman2, pokeman3, player, true, place);
    EXPECT_EQ(battle->getIndex(pokeman2), 5);
}

TEST(Battle, GetIndexFlying) {
    Vulture* pokeman2 = new Vulture(100, 100, 100, 1, new MediumLevel());
    Agility* pokeman3 = new Agility(0, 100, 100, 1, new MediumLevel());
    Player* player = new Player();
    Pokehub* place = new Pokehub();
            
    Battle* battle = new Battle(pokeman2, pokeman3, player, true, place);
    EXPECT_EQ(battle->getIndex(pokeman2), 6);
}

TEST(Battle, GetIndexDark) {
    Oger* pokeman2 = new Oger(100, 100, 100, 1, new MediumLevel());
    Agility* pokeman3 = new Agility(0, 100, 100, 1, new MediumLevel());
    Player* player = new Player();
    Pokehub* place = new Pokehub();
            
    Battle* battle = new Battle(pokeman2, pokeman3, player, true, place);
    EXPECT_EQ(battle->getIndex(pokeman2), 7);
}

TEST(Battle, GetIndexPsychic) {
    Tele* pokeman2 = new Tele(100, 100, 100, 1, new MediumLevel());
    Agility* pokeman3 = new Agility(0, 100, 100, 1, new MediumLevel());
    Player* player = new Player();
    Pokehub* place = new Pokehub();
            
    Battle* battle = new Battle(pokeman2, pokeman3, player, true, place);
    EXPECT_EQ(battle->getIndex(pokeman2), 8);
}

TEST(Battle, GetIndexSteel) {
    Anodized* pokeman2 = new Anodized(100, 100, 100, 1, new MediumLevel());
    Agility* pokeman3 = new Agility(0, 100, 100, 1, new MediumLevel());
    Player* player = new Player();
    Pokehub* place = new Pokehub();
            
    Battle* battle = new Battle(pokeman2, pokeman3, player, true, place);
    EXPECT_EQ(battle->getIndex(pokeman2), 9);
}

TEST(Battle, InventoryPotion) {
    Agility* pokeman2 = new Agility(100, 100, 100, 1, new MediumLevel());
    Agility* pokeman3 = new Agility(0, 100, 100, 1, new MediumLevel());
    Player* player = new Player();
    Pokehub* place = new Pokehub();
    pokeman2->setHealth(pokeman2->getHealth() - 20);
    player->addItem(new SmallPotion());
            
    Battle* battle = new Battle(pokeman2, pokeman3, player, true, place);
    stringstream out;
    istringstream in;
    in.str("1\n");
    battle->inventory(in, out);
    EXPECT_EQ(out.str(), "Choose an item, or 0 to leave:\n");
    EXPECT_EQ(player->getInventory().size(), 0);
    EXPECT_EQ(pokeman2->getHealth(), 100);
}

TEST(Battle, InventoryPokesphere) {
    Agility* pokeman2 = new Agility(100, 100, 100, 1, new MediumLevel());
    Agility* pokeman3 = new Agility(1, 100, 100, 1, new MediumLevel());
    Player* player = new Player();
    Pokehub* place = new Pokehub();
    CommonSphere* i = new CommonSphere();
    i->setRand(0);
    player->addItem(i);
            
    Battle* battle = new Battle(pokeman2, pokeman3, player, true, place);
    stringstream out;
    istringstream in;
    in.str("1\n");
    battle->inventory(in, out);
    EXPECT_EQ(out.str(), "Choose an item, or 0 to leave:\n");
    EXPECT_EQ(place->getPSUSize(), 1);
}

TEST(Battle, InventoryNotValid) {
    Agility* pokeman2 = new Agility(100, 100, 100, 1, new MediumLevel());
    Agility* pokeman3 = new Agility(1, 100, 100, 1, new MediumLevel());
    Player* player = new Player();
    Pokehub* place = new Pokehub();
    
    Battle* battle = new Battle(pokeman2, pokeman3, player, true, place);
    stringstream out;
    istringstream in;
    in.str("1\n0\n2\n");
    battle->inventory(in, out);
    EXPECT_EQ(out.str(), "Choose an item, or 0 to leave:\nPlease choose an available item\n");
}

TEST(Battle, InventoryEnd) {
    Agility* pokeman2 = new Agility(100, 100, 100, 1, new MediumLevel());
    Agility* pokeman3 = new Agility(1, 100, 100, 1, new MediumLevel());
    Player* player = new Player();
    Pokehub* place = new Pokehub();

    Battle* battle = new Battle(pokeman2, pokeman3, player, true, place);
    stringstream out;
    stringstream in;
    in.str("0\n3\n");
    battle->inventory(in, out);
    EXPECT_EQ(out.str(), "Choose an item, or 0 to leave:\n");
}
