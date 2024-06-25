#include "../header/player.h"
#include "../header/Item.hpp"

/*Player::~Player(){
	for(Character* character : pokeman){
		delete character;
	}
	for(Item* item : inventory){
		delete item;
}*/

Player::Player() {
    setToPokeman(false);
}

Player::~Player() {
    for(unsigned int i = 0; i < pokeman.size(); ++i) {
        delete pokeman.at(i);
    }
    for(unsigned int i = 0; i < inventory.size(); ++ i) {
        delete inventory.at(i);
    }
}

std::vector<Character*>& Player::getPokeman() {

    return pokeman;
}

std::vector<Item*>& Player::getInventory() {
    return inventory;
}

void Player::setPokeman(std::vector<Character*>& newPokeman) {
    pokeman = newPokeman;
}

void Player::setInventory(std::vector<Item*>& newInventory) {
    inventory = newInventory;
}

void Player::addItem(Item* newItem) {
    if(newItem != nullptr) {
        inventory.push_back(newItem);
    }
}
