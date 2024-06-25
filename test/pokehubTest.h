#include "../header/pokehub.h"
#include "../header/oger.h"
#include "../header/slowLevel.h"
#include "../header/anodized.h"
#include "../header/agility.h"
#include "../header/mediumLevel.h"
#include <iostream>

TEST(Pokehub, heal){
	Pokehub pub;
	std::vector<Character*> list{new Oger(100, 100, 100, 1, new SlowLevel()), new Agility(100, 100, 100, 1, new SlowLevel()), new Anodized(100, 100, 100, 1, new MediumLevel())};
	list.at(0)->setHealth(5);
	list.at(1)->setHealth(69);
	list.at(2)->setHealth(21);
	pub.heal(list);
	EXPECT_EQ(list.at(0)->getHealth(), 100);
	EXPECT_EQ(list.at(1)->getHealth(), 100);
	EXPECT_EQ(list.at(2)->getHealth(), 100);
}

TEST(Pokehub, accessPSU){
	std::string input="n\n";
	Pokehub hub;
	hub.addPokeman(new Oger(100, 100, 100, 1, new MediumLevel()));
	std::vector<Character*> list{new Oger(100, 100, 100, 1, new SlowLevel()), new Agility(100, 100, 100, 1, new SlowLevel()), new Anodized(100, 100, 100, 1, new MediumLevel())};
	Player* player = new Player();
	player->setPokeman(list);
	std::stringstream str1;
	std::istringstream* str2 = new std::istringstream(input);;
	hub.accessPSU(player, str1, str2);
	EXPECT_EQ(str1.str(), "Hello! Would you like to swap some pokemans?\nEnter 'Y' or 'y' for yes or 'N' or 'n' for no\nPlease come again!\n");
}

TEST(Pokehub, swapPokeman){
	std::string input="y\n1\n2\n";
	Pokehub hub;
	hub.addPokeman(new Oger(100, 100, 100, 1, new MediumLevel()));
	std::vector<Character*> list{new Oger(100, 100, 100, 1, new SlowLevel()), new Agility(100, 100, 100, 1, new SlowLevel()), new Anodized(100, 100, 100, 1, new MediumLevel())};
	Player* player = new Player();
	player->setPokeman(list);
	std::stringstream str1;
	std::istringstream* str2 = new std::istringstream(input);
	hub.accessPSU(player, str1, str2);
	EXPECT_EQ(str1.str(), "Hello! Would you like to swap some pokemans?\nEnter 'Y' or 'y' for yes or 'N' or 'n' for no\nAccessing PSU database...\nConfirmed identity\n    1. Oger\nWhich pokeman do you want?\nEnter the number that corresponds\n    1. Oger\n    2. Agility\n    3. Anodized\nWhich pokeman do you want to switch out?\nEnter the number that corresponds\nOger has been swapped with Agility\n");
}
TEST(Pokehub, addPokeman){
	Pokehub hub;
	hub.addPokeman(new Oger(100, 100, 100, 1, new MediumLevel()));
	EXPECT_EQ(hub.getPSUSize(), 1);
}

TEST(Pokehub, printAllPokeman){
	Pokehub hub;
	hub.addPokeman(new Oger(100, 100, 100, 1, new MediumLevel()));
	std::vector<Character*> list{new Oger(100, 100, 100, 1, new SlowLevel()), new Agility(100, 100, 100, 1, new SlowLevel()), new Anodized(100, 100, 100, 1, new MediumLevel())};
	std::stringstream str;
	hub.printAllPokeman(list, str);
	EXPECT_EQ(str.str(), "    1. Oger\n    2. Agility\n    3. Anodized\n");
}
