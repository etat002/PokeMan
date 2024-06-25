#include"../header/MasterSphere.hpp"
#include"../header/character.h"
#include<iostream>
#include"../header/agility.h"
#include"../header/mediumLevel.h"
#include"../header/pokehub.h"
TEST(MasterSphere,success)
{
Character* x = new Agility(100,100,100,1,new MediumLevel());
MasterSphere* test = new MasterSphere();
test->setRand(0);
stringstream s;
Pokehub* t;
test->action(x,s,t);
EXPECT_EQ(s.str(),"Congrat! you have successfully captured a new PokeMan\n");
}

TEST(MasterSphere,fail)
{
Character* x = new Character();
MasterSphere* test = new MasterSphere();
test->setRand(100);
stringstream s;
Pokehub* t;
test->action(x,s,t);
EXPECT_EQ(s.str(),"you have failed to capture the PokeMan\n");
}
