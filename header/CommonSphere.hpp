#ifndef __commonSphere_hpp__
#define __commonSphere_hpp__
#include "Item.hpp"
#include "character.h"
#include <iostream>
#include "pokehub.h"
using namespace std;

class CommonSphere: public Item
{
private:
	int chance = 25;
	int randNum = rand()%100;
public:
	CommonSphere(){
		setName("Common Sphere");
		setPokesphere(true);
		setDescription("This is a common sphere");
	}
	virtual void action(Character* x,ostream& p,Pokehub* t)
	{
		if (randNum<= chance+25*(1-x->getHealth()/x->getMaxHealth())) {
			t->addPokeman(x);
			p<<"Congrat! you have successfully captured a new PokeMan" <<endl;
			std::cout << "Finish the fight to show dominance." << std::endl;
			x->setCaught(true);
	}
		else {p<<"you have failed to capture a new Pokeman"<< endl;}}
	void setRand(int num)
	{
		randNum = num;
	}
};
#endif
