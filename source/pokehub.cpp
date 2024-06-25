#include "../header/pokehub.h"
#include <iostream>

void Pokehub::heal(std::vector<Character*>& current){
	for(Character* i:current){
		i->setHealth(i->getMaxHealth());
	}
	std::cout << "Your pokeman got healthed!\n";
}

void Pokehub::swapPokeman(std::vector<Character*>& current, std::ostream& out, std::istream* in){
	int selection = -1, onParty = -1;
	printAllPokeman(PSU, out);
	out << "Which pokeman do you want?\nEnter the number that corresponds" << std::endl;
	while(!((*in) >> selection) || ((selection>PSU.size() || selection<1))){
		in->clear();
		in->ignore(500 , '\n');
		out << "Please enter a valid integer that corresponds with a pokeman available" << std::endl;
	}
	printAllPokeman(current, out);
	out << "Which pokeman do you want to switch out?\nEnter the number that corresponds" << std::endl;
	while(!((*in) >> onParty) || (onParty>3 || onParty<1)){
		in->clear();
		in->ignore(500, '\n');
		out << "Please enter a number 1-3" << std::endl;
	}
	selection -= 1;
	onParty -= 1;
	Character* temp = current.at(onParty);
	current.at(onParty) = PSU.at(selection);
	PSU.at(selection) = temp;
	out << current.at(onParty)->getName() << " has been swapped with " << PSU.at(selection)->getName() << std::endl;
}

void Pokehub::accessPSU(Player* player, std::ostream& out, std::istream* in){
	char input;
	out << "Hello! Would you like to swap some pokemans?" << std::endl;
	out << "Enter 'Y' or 'y' for yes or 'N' or 'n' for no" << std::endl;
	in->get(input);
	while (input != 'Y' && input != 'y' && input != 'N' && input != 'n'){
		out << "Please input a valid response." << std::endl;
		out << "Enter 'Y' or 'Y' for yes or 'N' or 'n' for no" << std::endl;
		in->get(input);
	}
	if (input == 'Y' || input == 'y'){
		out << "Accessing PSU database..." << std::endl;
		out << "Confirmed identity" << std::endl;
                if(PSU.size() == 0) {
                        std::cout << "Try catching some pokeman first bro." << std::endl;
                }
                else {
		        swapPokeman(player->getPokeman(), out, in);
                }
	}
	else{
		out << "Please come again!" << std::endl;
	}
}

void Pokehub::printAllPokeman(std::vector<Character*>& list, std::ostream& out){
	int i=1;
	std::string blank = "    ";;
	for(Character* character: list){
		out << blank << i << ". " << character->getName() << std::endl;
		i++;
	}
}

void Pokehub::addPokeman(Character* pokeman){
	PSU.push_back(pokeman);
}

int Pokehub::getPSUSize(){
	return PSU.size();
}

Pokehub::~Pokehub(){
	for (Character* character : PSU){
		delete character;
	}
}
