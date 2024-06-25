#include <iostream>
#include "../header/battle.h"
#include "../header/Item.hpp" 

Battle::Battle(Character* mainCharacter, Character* opponent, Player* player, bool wildBattle, Pokehub* hub) {
    this->mainCharacter = mainCharacter;
    this->opponent = opponent;
    this->player = player;
    this->wildBattle = wildBattle;
    this->hub = hub;

    multiplier[0][0] = 0.5; multiplier[0][1] = 2.0; multiplier[0][2] = 0.5; multiplier[0][3] = 1.0; multiplier[0][4] = 0.5;
    multiplier[0][5] = 1.0; multiplier[0][6] = 1.0; multiplier[0][7] = 1.0; multiplier[0][8] = 1.0; multiplier[0][9] = 2.0;

    multiplier[1][0] = 0.5; multiplier[1][1] = 0.5; multiplier[1][2] = 2.0; multiplier[1][3] = 1.0; multiplier[1][4] = 2.0;
    multiplier[1][5] = 1.0; multiplier[1][6] = 0.5; multiplier[1][7] = 1.0; multiplier[1][8] = 1.0; multiplier[1][9] = 0.5;

    multiplier[2][0] = 2.0; multiplier[2][1] = 0.5; multiplier[2][2] = 0.5; multiplier[2][3] = 1.0; multiplier[2][4] = 2.0;
    multiplier[2][5] = 1.0; multiplier[2][6] = 1.0; multiplier[2][7] = 1.0; multiplier[2][8] = 1.0; multiplier[2][9] = 1.0;

    multiplier[3][0] = 1.0; multiplier[3][1] = 0.5; multiplier[3][2] = 2.0; multiplier[3][3] = 0.5; multiplier[3][4] = 1.0;
    multiplier[3][5] = 1.0; multiplier[3][6] = 2.0; multiplier[3][7] = 1.0; multiplier[3][8] = 1.0; multiplier[3][9] = 1.0;

    multiplier[4][0] = 2.0; multiplier[4][1] = 1.0; multiplier[4][2] = 1.0; multiplier[4][3] = 1.0; multiplier[4][4] = 1.0;
    multiplier[4][5] = 0.5; multiplier[5][6] = 2.0; multiplier[4][7] = 1.0; multiplier[4][8] = 1.0; multiplier[4][9] = 0.5;

    multiplier[5][0] = 1.0; multiplier[5][1] = 1.0; multiplier[5][2] = 1.0; multiplier[5][3] = 1.0; multiplier[5][4] = 2.0;
    multiplier[5][5] = 1.0; multiplier[5][6] = 0.5; multiplier[5][7] = 2.0; multiplier[5][8] = 0.5; multiplier[5][9] = 2.0;

    multiplier[6][0] = 1.0; multiplier[6][1] = 2.0; multiplier[6][2] = 1.0; multiplier[6][3] = 0.5; multiplier[6][4] = 0.5;
    multiplier[6][5] = 2.0; multiplier[6][5] = 1.0; multiplier[6][7] = 1.0; multiplier[6][8] = 1.0; multiplier[6][9] = 0.5;

    multiplier[7][0] = 1.0; multiplier[7][1] = 1.0; multiplier[7][2] = 1.0; multiplier[7][3] = 1.0; multiplier[7][4] = 1.0;
    multiplier[7][5] = 0.5; multiplier[7][6] = 1.0; multiplier[7][7] = 0.5; multiplier[7][8] = 2.0; multiplier[7][9] = 1.0;

    multiplier[8][0] = 1.0; multiplier[8][1] = 1.0; multiplier[8][2] = 1.0; multiplier[8][3] = 1.0; multiplier[8][4] = 1.0;
    multiplier[8][5] = 2.0; multiplier[8][6] = 1.0; multiplier[8][7] = 0.0; multiplier[8][8] = 0.5; multiplier[8][9] = 0.5;

    multiplier[9][0] = 0.5; multiplier[9][1] = 1.0; multiplier[9][2] = 0.5; multiplier[9][3] = 0.5; multiplier[9][4] = 2.0;
    multiplier[9][5] = 1.0; multiplier[9][6] = 1.0; multiplier[9][7] = 1.0; multiplier[9][8] = 1.0; multiplier[9][9] = 0.5;
}

void Battle::fight(istream& in) {
    int turn = 0;
    bool playsFirst = false;

    if(mainCharacter->getSpeed() >= opponent->getSpeed()) {
        playsFirst = true;
    }
    else {
        playsFirst = false;
    }

    while(!isOver()) {
        if(turn % 2 == 0) {
            if(playsFirst) {
                outputToConsole(std::cout);
                playerInput(in, std::cout);
            }
            else {
                opponentInput();
            }
        }
        else {
            if(playsFirst) {
                opponentInput();
            }
            else {
                outputToConsole(std::cout);
                playerInput(in, std::cout);
            }
        }
        ++turn;
    }
}

void Battle::playerInput(std::istream& in, std::ostream& out) {
    int input = -1;

    out << "Choose an attack 1-4 or enter 5 to check inventory:" << std::endl;
    while(!(in >> input) || (input < 1 || input > 5)) {
        in.clear();
        in.ignore(100, '\n');
        out << "Please input a valid response." << std::endl;
    }

    if(input >= 1 && input < 5) {
        distributeDamage(opponent, determineDamage(mainCharacter, opponent, input - 1));
    }
    else {
        inventory(in, out);
    }
}

void Battle::opponentInput() {
   int i = -1;
   i = std::rand() % 4;
   distributeDamage(mainCharacter, determineDamage(opponent, mainCharacter, i));
}

double Battle::determineDamage(Character* attacker, Character* defender, int attack) {
    double characterAttackStrength = -1;
    double mult = -1;
    double damage = -1;
    double attackDamage = -1;

    characterAttackStrength = attacker->getAttackStrength();
    mult = multiplier[getIndex(attacker)][getIndex(defender)];
    attackDamage = attacker->getAttacks().at(attack)->getAtk();
    damage = characterAttackStrength * attackDamage * mult;

    return damage;
}

void Battle::distributeDamage(Character* attacked, double damage) {
    cout << attacked->getName() << " has taken " << damage << " damage." << std::endl;
    attacked->setHealth(attacked->getHealth() - damage);
}

void Battle::outputToConsole(ostream& out) {
    out << std::endl << mainCharacter->getName() << " " << mainCharacter->getHealth() << " health." << std::endl;
    out << opponent->getName() << " " << opponent->getHealth() << " health." << std::endl << std::endl;

    for(unsigned int i = 0; i < mainCharacter->getAttacks().size(); ++i) {
        out << "    " << i + 1 << ". " <<  mainCharacter->getAttacks().at(i)->getAtkName() <<
                  " " << determineDamage(mainCharacter, opponent, i) << " health." << std::endl; 
    }
}

bool Battle::isOver() {
    return (mainCharacter->getHealth() == 0 || opponent->getHealth() == 0);
}

int Battle::getIndex(Character* pokeman) {
    if(pokeman->getType() == fire) {
        return 0;
    }
    else if(pokeman->getType() == grass) {
        return 1;
    }
    else if(pokeman->getType() == water) {
        return 2;
    }
    else if(pokeman->getType() == electric) {
        return 3;
    }
    else if(pokeman->getType() == rock) {
        return 4;
    }
    else if(pokeman->getType() == fighting) {
        return 5;
    }
    else if(pokeman->getType() == flying) {
        return 6;
    }
    else if(pokeman->getType() == dark) {
        return 7;
    }
    else if(pokeman->getType() == psychic) {
        return 8;
    }
    else {
        return 9;
    }
}

void Battle::inventory(istream& in, ostream& out) {
    int input = -1;
    for(unsigned int i = 0; i < player->getInventory().size(); ++i) {
       std:: cout << "    " << i + 1 << ". " << player->getInventory().at(i)->getName() << 
             ": " << player->getInventory().at(i)->getDescription() << std::endl;
    }

    out << "Choose an item, or 0 to leave:" << std::endl;
    do {
        while(!(in >> input) || (input < 0 || input > player->getInventory().size())) {
            in.clear();
            in.ignore(100, '\n');
            out << "Please choose an available item";
            if(wildBattle == false) {
                out << ", note pokesphere's are not allowed in trainer battles:";
            }
            out << std::endl;
        }
    }
    while(wildBattle == false && input != 0 && (player->getInventory().at(input - 1)->getName() == "Common Sphere" ||
          player->getInventory().at(input - 1)->getName() == "Rare Sphere" || 
          player->getInventory().at(input - 1)->getName() == "Master Sphere"));

    if(input != 0) {
        if(player->getInventory().at(input - 1)->getIfPokesphere()) {
            player->getInventory().at(input - 1)->action(opponent, std::cout, hub);
        }
        else {
            player->getInventory().at(input - 1)->action(mainCharacter, std::cout, hub);
        }
        delete player->getInventory().at(input - 1);
        player->getInventory().at(input - 1) = player->getInventory().at(player->getInventory().size() - 1);
        player->getInventory().pop_back();
    }
    else {
        outputToConsole(std::cout);
        playerInput(in, std::cout);
    }
}
