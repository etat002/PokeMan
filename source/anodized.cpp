#include <cstdlib>
#include <ctime>
#include "../header/anodized.h"
#include "../header/Steel.hpp"
#include "../header/Kick.hpp"
#include "../header/Tackle.hpp"
#include "../header/Scratch.hpp"

Anodized::Anodized(double health, double speed, double attackStrength, int level, LevelStrategy* levelUpStrategy) {
    setName("Anodized");
    setDescription("Pure metal.  You won't leave a dent.");
    setType(steel);
    setSpeed(speed);
    setLevelUpStrategy(levelUpStrategy);
    setLevel(level);
    setMaxHealth(health);
    setHealth(health);
    setAttackStrength(attackStrength);
    vector<AttackStrategy*> newAttacks = {new Steel(), new Kick(), new Tackle(), new Scratch()};
    setAttacks(newAttacks);
    setToPokeman(true);
}
/*
Anodized::~Anodized(){
	Character::~Character();
}*/
