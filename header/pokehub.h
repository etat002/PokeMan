#ifndef __pokehub_h__
#define __pokehub_h__
#include <vector>
#include "character.h"
#include "player.h"
#include <iostream>

class Pokehub{
private:
	std::vector<Character*> PSU;
public:
	~Pokehub();
	void heal(std::vector<Character*>& current);
	void accessPSU(Player* player, std::ostream& out, std::istream* in);
	void swapPokeman(std::vector<Character*>& current, std::ostream& out, std::istream* in);
	void printAllPokeman(std::vector<Character*>& list, std::ostream& out);
	void addPokeman(Character* pokeman);
	int getPSUSize();
};

#endif
