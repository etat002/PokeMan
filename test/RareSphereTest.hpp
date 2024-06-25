#include"../header/RareSphere.hpp"
#include"../header/character.h"
#include<iostream>
#include"../header/agility.h"
#include"../header/mediumLevel.h" 
#include"../header/pokehub.h"
TEST(RareSphere,success)
{
Character* x = new Agility(100,100,100,1,new MediumLevel());
RareSphere* test = new RareSphere();
test->setRand(0);
stringstream s;
Pokehub* t;
test->action(x,s,t);
EXPECT_EQ(s.str(),"Congrat! you have successfully captured a new PokeMan\n");
}

TEST(RareSphere,fail)
{
Character* x = new Character();
RareSphere*test = new RareSphere();
test->setRand(-50);
stringstream s;
Pokehub* t;
test->action(x,s,t);
EXPECT_EQ(s.str(),"you have failed to capture the PokeMan\n");
}
