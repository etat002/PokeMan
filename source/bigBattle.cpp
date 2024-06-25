#include "../header/bigBattle.h"
#include "../header/battle.h"

#include <iostream>

using namespace std;

BigBattle::BigBattle(Player* player, CharacterEntity* opponent, Pokehub* hub): player(player), opponent(opponent), hub(hub) {}

void BigBattle::startBattle(istream& in) {
    Character* playerCharacter = player->getPokeman().at(0);
    Character* opponentCharacter;
    int i = -1000000;
    bool wildFight = false;

    if(!opponent->getIfPokeman()) {
        Player* opponentCast = static_cast<Player*>(opponent);
        opponentCharacter = opponentCast->getPokeman().at(0);
        i = 0;
    }
    else {
        opponentCharacter = static_cast<Character*>(opponent);
        wildFight = true;
    }

    Battle* currentBattle;

    while(!battleOver(std::cout)) {
        // Add characters to battle
        currentBattle = new Battle(playerCharacter, opponentCharacter, player, wildFight, hub);
        currentBattle->fight(in);

        if(playerCharacter->getHealth() <= 0) {
            std::cout << std::endl << playerCharacter->getName() << " has been defeated!" << std::endl;
            if(!battleOver(std::cout)) {
                swapPokeman(playerCharacter, std::cout, std::cin);
            }
        }
        else {
            if(i >= 0  && i < 2) {
                Player* opponentCast = static_cast<Player*>(opponent);
                std::cout << std::endl << opponentCast->getPokeman().at(i)->getName() << " has been defeated!" << std::endl;
                ++i;
                opponentCharacter = opponentCast->getPokeman().at(i);
            }
        }
        delete currentBattle;
    }
}

void BigBattle::swapPokeman(Character*& toSwap, ostream& out, istream& in) {
    int input = -1;

    printPokeman();
    out << "Choose a pokeman to send to battle 1-3:" << endl;
    while(!(in >> input) || (input < 1 || input > 3 || player->getPokeman().at(input - 1)->getHealth() == 0)) {
        in.clear();
        in.ignore(100, '\n');
        printPokeman();
        out << "Please choose a pokeman between 1-3 with non-zero health:" << endl;
    }

    out << player->getPokeman().at(input - 1)->getName() << " has been sent to battle." << endl;
    toSwap = player->getPokeman().at(input - 1);
}

void BigBattle::printPokeman() {
    for(unsigned int i = 0; i < player->getPokeman().size(); ++i) {
        cout << "    " << i + 1 << ". " << player->getPokeman().at(i)->getName()  << ", level: "
             << player->getPokeman().at(i)->getLevel()  << ", health: " << player->getPokeman().at(i)->getHealth()
             << ", speed: " << player->getPokeman().at(i)->getSpeed() << endl;
    }
}

bool BigBattle::battleOver(ostream& out) {
    if(player->getPokeman().at(0)->getHealth() == 0 && player->getPokeman().at(1)->getHealth() == 0 &&
       player->getPokeman().at(2)->getHealth() == 0) {
        out << "You have lost the battle." << endl;
        return true;
    }
    else if(!opponent->getIfPokeman()) {
        Player* op = static_cast<Player*>(opponent);
        if(op->getPokeman().at(0)->getHealth() == 0 && op->getPokeman().at(1)->getHealth() == 0 &&
           op->getPokeman().at(2)->getHealth() == 0) {
            out << "You have won the battle." << endl;
            for(unsigned int i = 0; i < player->getPokeman().size(); ++i) {
                player->getPokeman().at(i)->updateExperience();
            }
            return true;
        }
    }
    else if(opponent->getIfPokeman()) {
        Character* op = static_cast<Character*>(opponent);
        if(op->getHealth() == 0) {
            for(unsigned int i = 0; i < player->getPokeman().size(); ++i) {
                player->getPokeman().at(i)->updateExperience();
            }
            out << "You have won the battle." << endl;
            return true;
        }
    }
    return false;
}
