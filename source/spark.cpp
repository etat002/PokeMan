#include <cstdlib>
#include <ctime>
#include "../header/spark.h"
#include "../header/Fire.hpp"
#include "../header/Kick.hpp"
#include "../header/Tackle.hpp"
#include "../header/Scratch.hpp"

Spark::Spark(double health, double speed, double attackStrength, int level, LevelStrategy* levelUpStrategy) {
    setName("Spark");
    setDescription("It only takes a spark to start a fire.  This guy leaves flames where it goes.");
    setType(fire);
    setSpeed(speed);
    setLevelUpStrategy(levelUpStrategy);
    setLevel(level);
    setMaxHealth(health);
    setHealth(health);
    setAttackStrength(attackStrength);
    vector<AttackStrategy*> newAttacks = {new Fire(), new Kick(), new Tackle(), new Scratch()};
    setAttacks(newAttacks);
    setToPokeman(true);
}
/*
Spark::~Spark(){
	Character::~Character();
}*/
