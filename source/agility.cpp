#include <cstdlib>
#include <ctime>
#include "../header/agility.h"
#include "../header/Fighting.hpp"
#include "../header/Kick.hpp"
#include "../header/Tackle.hpp"
#include "../header/Scratch.hpp"

Agility::Agility(double health, double speed, double attackStrength, int level, LevelStrategy* levelUpStrategy) {
    setName("Agility");
    setDescription("This pokeman was born to fight.  You might be knocked out.");
    setType(fighting);
   // setMaxHealth(health);
   // setHealth(health);
    setSpeed(speed);
  // setAttackStrength(attackStrength);
    setLevelUpStrategy(levelUpStrategy);
    setLevel(level);
    setMaxHealth(health);
    setHealth(health);
    setAttackStrength(attackStrength);
    vector<AttackStrategy*> newAttacks = {new Fighting(), new Kick(), new Tackle(), new Scratch()};
    setAttacks(newAttacks);
    setToPokeman(true);
}
/*
Agility::~Agility(){
	Character::~Character();
}*/
