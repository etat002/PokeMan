#ifndef _BATTLE_H_
#define _BATTLE_H_

#include <iostream>
#include "player.h"
#include "character.h"
#include "pokehub.h"

class Battle {
private:
    Character* mainCharacter;
    Character* opponent;
    Player* player;
    double multiplier[10][10];
    bool wildBattle;
    Pokehub* hub;
public:
    Battle(Character*, Character*, Player*, bool, Pokehub*);
    void fight(istream&);
    void playerInput(istream&, ostream&);
    void opponentInput();
    double determineDamage(Character*, Character*, int);
    void distributeDamage(Character*, double);
    void outputToConsole(ostream&);
    bool isOver();
    int getIndex(Character*);
    void inventory(istream&, ostream&);
};

#endif
