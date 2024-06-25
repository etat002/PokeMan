#ifndef __mediumPotion_hpp__
#define __mediumPotion_hpp__
#include "character.h"
#include "Item.hpp"
#include <iostream>
#include "pokehub.h"

using namespace std;

class MediumPotion : public Item {
private:
	int healAmount = 40;
public:
	MediumPotion(){
		setName("Medium Potion");
		setPokesphere(false);
		setDescription("Ointment from appointment");
	}
	virtual void action(Character* x, ostream& p, Pokehub* t)
	{
		x->setHealth(healAmount + x->getHealth());
		p<<x->getName()<<"  is healed for 40 health" << endl;
	}
};
#endif
