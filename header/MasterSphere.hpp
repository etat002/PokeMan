#ifndef __masterSphere_hpp__
#define __masterSphere_hpp__
#include "character.h"
#include "Item.hpp"
#include <iostream>
#include "pokehub.h"
using namespace std;

class MasterSphere : public Item
{
private:
	int chance = 75;
	int randNum = rand()%100;
public:
        MasterSphere(){
		setName("Master Sphere");
		setPokesphere(true);
		setDescription("Gotta catch em all!");
	}
	virtual void action(Character* x, ostream& p,Pokehub* t){
		if (randNum<= chance+25*(1- x->getHealth() / x->getMaxHealth()))
			{ 
				t->addPokeman(x);
				p<< "Congrat! you have successfully captured a new PokeMan" << endl;	
                                std::cout << "Finish the fight to show dominance." << std::endl;
				x->setCaught(true);
			}
		else {p<< "you have failed to capture the PokeMan" <<endl; }
			 
		}
	void setRand(int num)
	{
		randNum = num;
	}
};
#endif	
