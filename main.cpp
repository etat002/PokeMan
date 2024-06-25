#include "header/characterEntity.h"
#include "header/character.h"
#include "header/player.h"
#include "header/shock.h"
#include "header/stone.h"
#include "header/agility.h"
#include "header/vulture.h"
#include "header/oger.h"
#include "header/tele.h"
#include "header/spark.h"
#include "header/anodized.h"
#include "header/weed.h"
#include "header/tidal.h"
#include "header/pokehub.h"
#include "header/slowLevel.h"
#include "header/mediumLevel.h"
#include "header/fastLevel.h"
#include "header/randomLevel.h"
#include "header/SmallPotion.hpp"
#include "header/MediumPotion.hpp"
#include "header/LargePotion.hpp"
#include "header/CommonSphere.hpp"
#include "header/RareSphere.hpp"
#include "header/MasterSphere.hpp"
#include "header/bigBattle.h"
#include "header/battle.h"
#include <ctime>
#include <iostream>
#include "header/Item.hpp"


using namespace std;

Player* randomOpponent(Player* player);
Character* randomPokeman(Player* player);

int main() {
	//Starter arc?
	srand(time(NULL));
	Player* player = new Player();
	std::cout << "Hello and welcome to the world of Pokeman." << std::endl;
	std::cout << "Of course, being in this world means that everyone should have a Pokeman of their own. So go ahead, choose a Pokeman!" << std::endl;
	std::vector<Character*> starters = {new Tidal(20, 7, 20, 1, new FastLevel()), new Weed(20, 7, 20, 1, new FastLevel()), new Spark(20, 7, 20, 1, new FastLevel())};
	for (int i=0; i<starters.size(); i++){
		std::cout << "    " << i+1 << ". " << starters.at(i)->getName() << " - " << starters.at(i)->getDescription() << std::endl;
	}
	int choice;
	while(!(std::cin >> choice) || choice < 1 || choice > 3){
		std::cin.clear();
		std::cin.ignore(500, '\n');
		std::cout << "A number between 1 and 3 would be nice." << std::endl;
	}
	std::cout << "All right well, there are two more Pokeman and no one else to take them, so here ya go kiddo have fun." << std::endl;
	player->setPokeman(starters);
	std::cout << "You have obtained the three starters!" << std::endl;
	
	//Go to main game
	BigBattle *bigBattle = nullptr;
	Pokehub *pub = new Pokehub();
	Player *opponent1 = nullptr;
	Character* wild = nullptr;
	char input = '\0';
	while(input != 'q' && input != 'Q'){
		std::cout << "What do you want to do?" << std::endl;
		std::cout << "    1. Search for wild pokemans" << std::endl;
		std::cout << "    2. Start a fight with a random trainer" << std::endl;
		std::cout << "    3. Head over to the pokehub" << std::endl;
		std::cout << "    4. Search the trash cans for an item" << std::endl;
		while(!(std::cin >> choice) || choice < 1 || choice > 4){
			std::cin.clear();
			std::cin.ignore(500, '\n');
			std::cout << "Please choose a valid option" << std::endl;
		}
		if(choice == 1){
			//start wild pokeman battle
			std::cout << "Oh wow a random pokeman" << std::endl;
                        wild = randomPokeman(player);
                        bigBattle = new BigBattle(player, wild, pub);
                        bigBattle->startBattle(std::cin);
                        delete bigBattle;
                        bigBattle = nullptr;
                        if(!wild->getCaught()) {
                            delete wild;
                            wild = nullptr;
                        }
		}
		else if(choice == 2){
			//start a trainer battle
			std::cout << "Oh no that guy looks angry" << std::endl;
                        opponent1 = randomOpponent(player);
                        bigBattle = new BigBattle(player, opponent1, pub);
                        bigBattle->startBattle(std::cin);
                        delete bigBattle;
                        bigBattle = nullptr;
                        delete opponent1;
                        opponent1 = nullptr;
		}
		else if(choice == 3){
			//start pokehub interactions
			std::cout << "Hello and welcome to the pokehub, I'm Nurse Jolly. What would you like to do today?" << std::endl;
			std::cout << "    1. Heal pokemans up" << std::endl;
			std::cout << "    2. Access PSU(Pokeman Storage Unit)" << std::endl;
			std::cout << "    3. Thank the nurse and leave" << std::endl;
			while (!(std::cin >> choice) || choice < 1 || choice > 3){
				std::cin.clear();
				std::cin.ignore(500, '\n');
				std::cout << "Nurse Jolly doesn't speak gibberish" << std::endl;
			}
			if (choice == 1){
				pub->heal(player->getPokeman());
			}
			else if(choice == 2){;
				pub->accessPSU(player, std::cout, &std::cin);
			}
			std::cout << "Nurse Jolly: Thank you and please come again! Or don't, you should win your battles more often." << std::endl;
		}
		else{
			int chance = rand()%1000;
			if (chance < 126){
				std::cout << "Hobo Hank was patrolling his humble abode. Scurry away in a hurry empty handed/" << std::endl;
			}
			else if(chance > 125 && chance < 251){
				std::cout << "Looks like it was trash day not too long ago. Not a speck of dust in sight!" << std::endl;
			}
			else if(chance > 250 && chance < 376){
				std::cout << "You came out empty handed, but not empty stomach!" << std::endl;
			}
			else if(chance > 375 && chance < 501){
				std::cout << "You ended up at the recycling center instead. Good on you for recylcing!" << std::endl;
			}
			else if(chance > 500 && chance < 651){
				std::cout << "You see cat with a pile of hair balls but notice one looked different. You found a Common Sphere!" << std::endl;
				player->addItem(new CommonSphere());
			}
			else if(chance > 650 && chance < 721){
				std::cout << "At the bottom of the trashcan you noticed a puddle of nondiscript liquid. You reached your hand in it and found a Rare Sphere! Too bad you didn't find any hand sanitizer." << std::endl;
				player->addItem(new RareSphere());
			}
			else if(chance > 720 && chance < 751){
				std::cout << "You gave up searching and all of a sudden some kid in Gucci drip across the street throws a pokesphere at you and laughs. You have obtained a Master Sphere." << std::endl;
				player->addItem(new MasterSphere());
			}
			else if(chance > 750 && chance < 951){
				std::cout << "You saw a Small Potion next to the banana peel you found from earlier." << std::endl;
				player->addItem(new SmallPotion());
			}
			else if(chance > 950 && chance < 970){
				std::cout << "You looked in the night stand and found a Medium Potion!" << std::endl;
				player->addItem(new MediumPotion());
			}
			else{
				std::cout << "You looked under the mattress and found a Large Potion!" << std::endl;
				player->addItem(new LargePotion());
			}
		}
		std::cout << "Do you want to look around and play more or quit? Type 'Q' or 'q' to quit or anything else to continue." << std::endl;
		while(!(std::cin >> input)){
			std::cin.clear();
			std::cin.ignore(500, '\n');
			std::cout << "Please enter something valid." << std::endl;
		}
	}
    delete player;
    delete pub;
}

Player* randomOpponent(Player* player){
	Player *opponent = new Player();
	std::vector<Character*> list = {randomPokeman(player), randomPokeman(player), randomPokeman(player)};
	opponent->setPokeman(list);
	return opponent;
}

Character* randomPokeman(Player* player){
	int highest = 0;
	for (Character* pokemans: player->getPokeman()){
		if (highest < pokemans->getLevel()){
			highest = pokemans->getLevel();
		}
	}
	int type = (rand()%10);
	int lvl = rand()%4;
	LevelStrategy* lvlStrat;
	if (lvl == 0){
		lvlStrat = new SlowLevel();
	}
	else if (lvl == 1){
		lvlStrat = new MediumLevel();
	}
	else if(lvl == 2){
		lvlStrat = new FastLevel();
	}
	else{
		lvlStrat = new RandomLevel();
	}
	if (type == 0){
		return new Agility((20+highest) + (rand()%20 - rand()%20), (rand()%10)+1, (20+highest) + (rand()%20 - rand()%20), highest + rand()%10 - rand()%10,lvlStrat);
	}
	else if (type == 1){
		return new Anodized((20+highest) + (rand()%20 - rand()%20), (rand()%10)+1, (20+highest) + (rand()%20 - rand()%20), highest + rand()%10 - rand()%10,lvlStrat);
	}
	else if (type == 2){
		return new Oger((20+highest) + (rand()%20 - rand()%20), (rand()%10)+1, (20+highest) + (rand()%20 - rand()%20), highest + rand()%10 - rand()%10,lvlStrat);
	}
	else if (type == 3){
		return new Shock((20+highest) + (rand()%20 - rand()%20), (rand()%10)+1, (20+highest) + (rand()%20 - rand()%20), highest + rand()%10 - rand()%10,lvlStrat);
	}
	else if (type == 4){
		return new Spark((20+highest) + (rand()%20 - rand()%20), (rand()%10)+1, (20+highest) + (rand()%20 - rand()%20), highest + rand()%10 - rand()%10,lvlStrat);
	}
	else if (type ==5){
		return new Stone((20+highest) + (rand()%20 - rand()%20), (rand()%10)+1, (20+highest) + (rand()%20 - rand()%20), highest + rand()%10 - rand()%10,lvlStrat);
	}
	else if (type == 6){
		return new Tele((20+highest) + (rand()%20 - rand()%20), (rand()%10)+1, (20+highest) + (rand()%20 - rand()%20), highest + rand()%10 - rand()%10,lvlStrat);
	}
	else if (type == 7){
		return new Tidal((20+highest) + (rand()%20 - rand()%20), (rand()%10)+1, (20+highest) + (rand()%20 - rand()%20), highest + rand()%10 - rand()%10,lvlStrat);
	}	
	else if (type == 8){
		return new Vulture((20+highest) + (rand()%20 - rand()%20), (rand()%10)+1, (20+highest) + (rand()%20 - rand()%20), highest + rand()%10 - rand()%10,lvlStrat);
	}
	else{
		return new Weed((20+highest) + (rand()%20 - rand()%20), (rand()%10)+1, (20+highest) + (rand()%20 - rand()%20), highest + rand()%10 - rand()%10,lvlStrat);
	}
}


