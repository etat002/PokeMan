#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <iostream>
#include <vector>
#include <string>
#include "characterEntity.h"
#include "character.h"

class Item;

class Player: public CharacterEntity {
private:
    std::vector<Character*> pokeman;
    std::vector<Item*> inventory;
public:
    Player();
    ~Player();
    std::vector<Character*>& getPokeman();
    std::vector<Item*>& getInventory();
    void setPokeman(std::vector<Character*>& newPokeman);
    void setInventory(std::vector<Item*>&);
    void addItem(Item*);
};


#endif
