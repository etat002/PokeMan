#ifndef __rareSphere_hpp__
#define __rareSphere_hpp__
#include "character.h"
#include "Item.hpp"
#include <iostream>
#include "pokehub.h"
using namespace std;


class RareSphere : public Item
{
private:
	int chance = 50;
	int randNum = rand()%100;
public:	
	RareSphere(){
		setName("Rare Sphere");
		setPokesphere(true);
		setDescription("Rare Sphere bb");
	}
	virtual void action(Character* x, ostream& p, Pokehub* t){
		if (randNum<= chance+25*(1- x->getHealth() / x->getMaxHealth())){
			t->addPokeman(x);  p<< "Congrat! you have successfully captured a new PokeMan" << endl;
                        std::cout << "Finish the fight to show dominance." << std::endl;
     			x->setCaught(true);
		}
		else {
			p<< "you have failed to capture the PokeMan\n";
		}
}
	void setRand(int num)
	{
		randNum = num;
	}
};
#endif	
