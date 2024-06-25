#include"../header/CommonSphere.hpp"
#include"../header/character.h"
#include<iostream>
#include"../header/agility.h"
#include"../header/mediumLevel.h"
#include"../header/pokehub.h"

TEST(CommonSphere,success){
	Character* x = new Agility(100,100,100,1,new MediumLevel());
	CommonSphere* test = new CommonSphere();
	test->setRand(0);
	stringstream s;
	Pokehub* t;
	test->action(x,s,t);
	EXPECT_EQ(s.str(),"Congrat! you have successfully captured a new PokeMan\n");
}

TEST(CommonSphere,fail)
{
Character* x = new Character();
CommonSphere* test = new CommonSphere();
test->setRand(100);
stringstream s;
Pokehub* t;
test->action(x,s,t);
EXPECT_EQ(s.str(),"you have failed to capture a new Pokeman\n");
}

