#include <cstdlib>
#include <ctime>
#include "../header/weed.h"
#include "../header/Grass.hpp"
#include "../header/Kick.hpp"
#include "../header/Tackle.hpp"
#include "../header/Scratch.hpp"

Weed::Weed(double health, double speed, double attackStrength, int level, LevelStrategy* levelUpStrategy) {
    setName("Weed");
    setDescription("This small pokeman may seem harmless, but keep your eye on it the next thing you know it'll be everywhere.  Almost impossible to get rid of.");
    setType(grass);
    setSpeed(speed);
    setLevelUpStrategy(levelUpStrategy);
    setLevel(level);
    setMaxHealth(health);
    setHealth(health);
    setAttackStrength(attackStrength);
    vector<AttackStrategy*> newAttacks = {new Grass(), new Kick(), new Tackle(), new Scratch()};
    setAttacks(newAttacks);
    setToPokeman(true);
}
/*
Weed::~Weed(){
	Character::~Character();
}*/
