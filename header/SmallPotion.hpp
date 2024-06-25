#ifndef __smallPotion_hpp__
#define __smallPotion_hpp__
#include"character.h"
#include"Item.hpp"
#include "pokehub.h"
#include<iostream>
#include<string>

using namespace std;

class SmallPotion : public Item {
private:
	int healAmount = 20;
public:
	SmallPotion(){
		setPokesphere(false);
		setName("Small Potion");
		setDescription("Bandaids stick on me");
	}	
	virtual void action(Character* x, ostream& p, Pokehub* t) 
	{
		x->setHealth(healAmount+x->getHealth());
		p<<x->getName()<<"  is healed for 20 health" <<endl;
	}	
};
#endif
