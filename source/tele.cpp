#include <cstdlib>
#include <ctime>
#include "../header/tele.h"
#include "../header/psychic.hpp"
#include "../header/Kick.hpp"
#include "../header/Tackle.hpp"
#include "../header/Scratch.hpp"

Tele::Tele(double health, double speed, double attackStrength, int level, LevelStrategy* levelUpStrategy) {
    setName("Tele");
    setDescription("This pokeman knows what those around it are thinking.  An unfair advantage.");
    setType(psychic);
    setSpeed(speed);
    setLevelUpStrategy(levelUpStrategy);
    setLevel(level);
    setMaxHealth(health);
    setHealth(health);
    setAttackStrength(attackStrength);
    vector<AttackStrategy*> newAttacks = {new Psychic(), new Kick(), new Tackle(), new Scratch()};
    setAttacks(newAttacks);
    setToPokeman(true);
}
/*
Tele::~Tele(){
	Character::~Character();
}*/
