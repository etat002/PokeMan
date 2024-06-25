#include <cstdlib>
#include <ctime>
#include "../header/stone.h"
#include "../header/Rock.hpp"
#include "../header/Kick.hpp"
#include "../header/Tackle.hpp"
#include "../header/Scratch.hpp"

Stone::Stone(double health, double speed, double attackStrength, int level, LevelStrategy* levelUpStrategy) {
    setName("Stone");
    setDescription("This simple pokeman is not the brightest.  What it lacks in smarts it makes up in strength.");
    setType(rock);
    setSpeed(speed);
    setLevelUpStrategy(levelUpStrategy);
    setLevel(level);
    setMaxHealth(health);
    setHealth(health);
    setAttackStrength(attackStrength);
    vector<AttackStrategy*> newAttacks = {new Rock(), new Kick(), new Tackle(), new Scratch()};
    setAttacks(newAttacks);
    setToPokeman(true);
}
/*
Stone::~Stone(){
	Character::~Character();
}*/

