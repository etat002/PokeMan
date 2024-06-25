#include <vector>
#include <sstream>
#include "../header/bigBattle.h"
#include "../header/pokehub.h"

TEST(BigBattle, SwapPokeman) {
    Player* player = new Player();
    std::vector<Character*> pokeman = {new Agility(100, 100, 100, 1, new MediumLevel()),
                                    new Anodized(100, 100, 100, 1, new MediumLevel()),
                                    new Stone(100, 100, 100, 1, new MediumLevel())};
    player->setPokeman(pokeman);
    Pokehub* p = new Pokehub();
    BigBattle battle(player, new Vulture(100, 100, 100, 1, new MediumLevel()), p);
    istringstream in;
    in.str("1\n");
    stringstream out;
    Character* temp = new Spark(100, 100, 100, 1, new MediumLevel());
    battle.swapPokeman(temp, out, in);

    EXPECT_EQ(temp->getName(), "Agility");
    EXPECT_EQ(out.str(), "Choose a pokeman to send to battle 1-3:\nAgility has been sent to battle.\n");
}

TEST(BigBattle, SwapPokeman2) {
    Player* player = new Player();
    std::vector<Character*> pokeman = {new Agility(100, 100, 100, 1, new MediumLevel()),
                                    new Anodized(100, 100, 100, 1, new MediumLevel()),
                                    new Stone(100, 100, 100, 1, new MediumLevel())};
    player->setPokeman(pokeman);
    Pokehub* p = new Pokehub();
    BigBattle battle(player, new Vulture(100, 100, 100, 1, new MediumLevel()), p);
    istringstream in; 
    in.str("2\n");
    stringstream out;
    Character* temp = new Spark(100, 100, 100, 1, new MediumLevel());
    battle.swapPokeman(temp, out, in);
    
    EXPECT_EQ(temp->getName(), "Anodized");
    EXPECT_EQ(out.str(), "Choose a pokeman to send to battle 1-3:\nAnodized has been sent to battle.\n");
}

TEST(BigBattle, SwapPokeman3) {
    Player* player = new Player();
    std::vector<Character*> pokeman = {new Agility(100, 100, 100, 1, new MediumLevel()),
                                    new Anodized(100, 100, 100, 1, new MediumLevel()),
                                    new Stone(100, 100, 100, 1, new MediumLevel())};
    player->setPokeman(pokeman);
    Pokehub* p = new Pokehub();
    BigBattle battle(player, new Vulture(100, 100, 100, 1, new MediumLevel()), p);
    istringstream in;
    in.str("3\n");
    stringstream out;
    Character* temp = new Spark(100, 100, 100, 1, new MediumLevel());
    battle.swapPokeman(temp, out, in);
    
    EXPECT_EQ(temp->getName(), "Stone");
    EXPECT_EQ(out.str(), "Choose a pokeman to send to battle 1-3:\nStone has been sent to battle.\n");
}

TEST(BigBattle, SwapPokeman41) {
    Player* player = new Player();
    std::vector<Character*> pokeman = {new Agility(100, 100, 100, 1, new MediumLevel()),
                                    new Anodized(100, 100, 100, 1, new MediumLevel()),
                                    new Stone(100, 100, 100, 1, new MediumLevel())};
    player->setPokeman(pokeman);
    Pokehub* p = new Pokehub();
    BigBattle battle(player, new Vulture(100, 100, 100, 1, new MediumLevel()), p);
    istringstream in;
    in.str("4\n1\n");
    stringstream out;
    Character* temp = new Spark(100, 100, 100, 1, new MediumLevel());
    battle.swapPokeman(temp, out, in);
    
    EXPECT_EQ(temp->getName(), "Agility");
    EXPECT_EQ(out.str(), "Choose a pokeman to send to battle 1-3:\nPlease choose a pokeman between 1-3 with non-zero health:\nAgility has been sent to battle.\n");
}

TEST(BigBattle, SwapPokemanZeroHealth1) {
    Player* player = new Player();
    std::vector<Character*> pokeman = {new Agility(100, 100, 100, 1, new MediumLevel()),
                                    new Anodized(0, 100, 100, 1, new MediumLevel()),
                                    new Stone(0, 100, 100, 1, new MediumLevel())};
    player->setPokeman(pokeman);
    Pokehub* p = new Pokehub();
    BigBattle battle(player, new Vulture(100, 100, 100, 1, new MediumLevel()), p);

    istringstream in;
    in.str("3\n1\n");
    stringstream out;
    Character* temp = new Spark(100, 100, 100, 1, new MediumLevel());
    battle.swapPokeman(temp, out, in);

    EXPECT_EQ(temp->getName(), "Agility");
    EXPECT_EQ(out.str(), "Choose a pokeman to send to battle 1-3:\nPlease choose a pokeman between 1-3 with non-zero health:\nAgility has been sent to battle.\n");
}

TEST(BigBattle, BattleOverWinCharacter) {
    Player* player = new Player();
    std::vector<Character*> pokeman = {new Agility(100, 100, 100, 1, new MediumLevel()),
                                    new Vulture(100, 100, 100, 1, new MediumLevel()),
                                    new Anodized(100, 100, 100, 1, new MediumLevel())};
    player->setPokeman(pokeman);
    Pokehub* p = new Pokehub();
    Character* opponent = new Spark(0, 100, 100, 1, new MediumLevel());
    BigBattle battle(player, opponent, p);
    stringstream out;

    EXPECT_EQ(battle.battleOver(out), true);
    EXPECT_EQ(out.str(), "You have won the battle.\n");
}

TEST(BigBattle, BattleOverWinPlayer) {
    Player* player = new Player();
    std::vector<Character*> pokeman = {new Agility(100, 100, 100, 1, new MediumLevel()),
                                    new Vulture(100, 100, 100, 1, new MediumLevel()),
                                        new Anodized(100, 100, 100, 1, new MediumLevel())};
    player->setPokeman(pokeman);
    Pokehub* p = new Pokehub();
    Player* opponent = new Player();
    std::vector<Character*> opponentPokeman = {new Spark(0, 100, 100, 1, new MediumLevel()),
                                            new Weed(0, 100, 100, 1, new MediumLevel()),
                                            new Tidal(0, 100, 100, 1, new MediumLevel())};
    opponent->setPokeman(opponentPokeman);
    BigBattle battle(player, opponent, p);
    stringstream out;
    
    EXPECT_EQ(battle.battleOver(out), true);
    EXPECT_EQ(out.str(), "You have won the battle.\n");
}

TEST(BigBattle, BattleOverLoseCharacter) {
    Player* player = new Player();
    std::vector<Character*> pokeman = {new Agility(0, 100, 100, 1, new MediumLevel()),
                                    new Vulture(0, 100, 100, 1, new MediumLevel()),
                                        new Anodized(0, 100, 100, 1, new MediumLevel())};
    player->setPokeman(pokeman);
    Pokehub* p = new Pokehub();
    Character* opponent = new Spark(100, 100, 100, 1, new MediumLevel());
    BigBattle battle(player, opponent, p);
    stringstream out;
    
    EXPECT_EQ(battle.battleOver(out), true);
    EXPECT_EQ(out.str(), "You have lost the battle.\n");
}

TEST(BigBattle, BattleOverLosePlayer) {
    Player* player = new Player();
    std::vector<Character*> pokeman = {new Agility(0, 100, 100, 1, new MediumLevel()),
                                    new Vulture(0, 100, 100, 1, new MediumLevel()),
                                        new Anodized(0, 100, 100, 1, new MediumLevel())};
    player->setPokeman(pokeman);
    Pokehub* p = new Pokehub();
    Player* opponent = new Player();
    std::vector<Character*> opponentPokeman = {new Spark(100, 100, 100, 1, new MediumLevel()),
                                            new Weed(100, 100, 100, 1, new MediumLevel()),
                                            new Tidal(100, 100, 100, 1, new MediumLevel())};
    opponent->setPokeman(opponentPokeman);
    BigBattle battle(player, opponent, p);
    stringstream out;
    
    EXPECT_EQ(battle.battleOver(out), true);
    EXPECT_EQ(out.str(), "You have lost the battle.\n");
}

TEST(BigBattle, BattleOverFalse) {
    Player* player = new Player();
    std::vector<Character*> pokeman = {new Agility(100, 100, 100, 1, new MediumLevel()),
                                    new Vulture(100, 100, 100, 1, new MediumLevel()),
                                        new Anodized(100, 100, 100, 1, new MediumLevel())};
    player->setPokeman(pokeman);
    Pokehub* p = new Pokehub();
    Character* opponent = new Spark(100, 100, 100, 1, new MediumLevel());
    BigBattle battle(player, opponent, p);
    stringstream out;
    
    EXPECT_EQ(battle.battleOver(out), false);
}
