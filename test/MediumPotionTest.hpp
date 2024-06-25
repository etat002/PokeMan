#include"../header/MediumPotion.hpp"
#include"../header/character.h"
#include<iostream>
#include<string>
#include"../header/agility.h"
#include"../header/mediumLevel.h"
#include"../header/pokehub.h"
TEST(MediumPotion, heal)
{
Character* x = new Agility(100,100,100,1,new MediumLevel());
x->setHealth(60);
MediumPotion* test = new MediumPotion();
stringstream s;
Pokehub* t;
test->action(x,s,t);
EXPECT_EQ(x->getHealth(),100);
}
