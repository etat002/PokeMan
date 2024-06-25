#include <cstdlib>
#include <ctime>
#include "../header/oger.h"
#include "../header/Dark.hpp"
#include "../header/Kick.hpp"
#include "../header/Scratch.hpp"
#include "../header/Tackle.hpp"

Oger::Oger(double health, double speed, double attackStrength, int level, LevelStrategy* levelUpStrategy) {
    setName("Oger");
    setDescription("??.  No one cares to find out.");
    setType(dark);
    setSpeed(speed);
    setLevelUpStrategy(levelUpStrategy);
    setLevel(level);
    setMaxHealth(health);
    setHealth(health);
    setAttackStrength(attackStrength);
    vector<AttackStrategy*> newAttacks = {new Dark(), new Kick(), new Scratch(), new Tackle()};
    setAttacks(newAttacks);
    setToPokeman(true);
}
/*
Oger::~Oger(){
	Character::~Character();
}*/
