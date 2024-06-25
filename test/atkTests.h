#include"../header/AttackStrategy.hpp"
#include"../header/Flying.hpp"
#include"../header/Fire.hpp"
#include"../header/Grass.hpp"
#include"../header/Electric.hpp"
#include"../header/Scratch.hpp"
#include"../header/Kick.hpp"
#include"../header/Water.hpp"
#include"../header/Fighting.hpp"
#include"../header/Dark.hpp"
#include"../header/Tackle.hpp"
#include"../header/Rock.hpp"
#include"../header/Steel.hpp"
#include"../header/psychic.hpp"
#include"../header/character.h"
//#include"SmallPotionTest.hpp"
//#include"MediumPotionTest.hpp"
//#include"LargePotionTest.hpp"
//#include"CommonSphereTest.hpp"
//#include"RareSphereTest.hpp"
//#include"MasterSphereTest.hpp"
#include<string>
#include"../header/Item.hpp"

TEST(Flying, damage)                  
{
Flying*  t = new Flying();
EXPECT_EQ(t->getAtkName(),"Flying Punch");
EXPECT_EQ(t->getAtk(), 0.6);
}

TEST(Water, damage)                  
{
Water* t  = new Water();
EXPECT_EQ(t->getAtkName(),"Water Punch");
EXPECT_EQ(t->getAtk(), 0.6);
}

TEST(Fire, damage)                  
{
Fire* t =  new Fire();
EXPECT_EQ(t->getAtkName(),"Fire Punch");
EXPECT_EQ(t->getAtk(), 0.6);
}

TEST(Rock, damage)                  
{
Rock* t = new Rock();
EXPECT_EQ(t->getAtkName(),"Rock Punch");
EXPECT_EQ(t->getAtk(), 0.6);
}

TEST(Grass, damage)                  
{
Grass* t = new Grass();
EXPECT_EQ(t->getAtkName(),"Grass Punch");
EXPECT_EQ(t->getAtk(), 0.6);
}

TEST(Steel, damage)                  
{
Steel* t = new Steel();
EXPECT_EQ(t->getAtkName(),"Steel Punch");
EXPECT_EQ(t->getAtk(), 0.6);
}

TEST(Dark, damage)                  
{
Dark* t = new Dark();
EXPECT_EQ(t->getAtkName(),"Dark Punch");
EXPECT_EQ(t->getAtk(), 0.6);
}

TEST(Electric, damage)                  
{
Electric* t = new Electric();
EXPECT_EQ(t->getAtkName(),"Electric Punch");
EXPECT_EQ(t->getAtk(), 0.6);
}

TEST(Psychic, damage)                  
{
Psychic* t = new Psychic();
EXPECT_EQ(t->getAtkName(),"Psychic Punch");
EXPECT_EQ(t->getAtk(), 0.6);
}

TEST(Fighting, damage)                  
{
Fighting* t = new Fighting();
EXPECT_EQ(t->getAtkName(),"Fighting Punch");
EXPECT_EQ(t->getAtk(), 0.6);
}

TEST(Kick, damage)                  
{
Kick* t= new Kick();
EXPECT_EQ(t->getAtkName(),"Kick");
EXPECT_EQ(t->getAtk(), 0.2);
}

TEST(Tackle, damage)                  
{
Tackle* t = new Tackle();
EXPECT_EQ(t->getAtkName(),"Tackle");
EXPECT_EQ(t->getAtk(), 0.2);
}

TEST(Scratch, damage)                  
{
Scratch* t = new Scratch();
EXPECT_EQ(t->getAtkName(),"Scratch");
EXPECT_EQ(t->getAtk(), 0.2);
}



