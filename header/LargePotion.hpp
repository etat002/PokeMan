#ifndef __largePotion_hpp__
#define __largePotion_hpp__
#include "character.h"
#include "Item.hpp"
#include <iostream>
#include "pokehub.h"

class LargePotion : public Item
{
private:
	int healAmount=60;
public:
	LargePotion(){
		setName("Large Potion");
		setPokesphere(false);
		setDescription("This was from the potion seller");
	}
	virtual void action(Character* x, ostream& p, Pokehub* t)
	{
		x->setHealth(healAmount+x->getHealth());
		p<<x->getName()<<"  is healed for 60 health"<<endl;
	}
};
#endif
