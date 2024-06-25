#ifndef _BIGBATTLE_H_
#define _BIGBATTLE_H_

#include <iostream>
#include "characterEntity.h"
#include "character.h"
#include "player.h"
#include "pokehub.h"

class BigBattle {
private:
    Player* player;
    CharacterEntity* opponent;
    Pokehub* hub;
public:
    BigBattle(Player*, CharacterEntity*, Pokehub*);
    void startBattle(istream&);
    void swapPokeman(Character*&, ostream&, istream&);
    void printPokeman();
    bool battleOver(ostream&);
};

#endif
