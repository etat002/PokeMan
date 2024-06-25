#include <cstdlib>
#include <ctime>
#include "../header/vulture.h"
#include "../header/Flying.hpp"
#include "../header/Kick.hpp"
#include "../header/Tackle.hpp"
#include "../header/Scratch.hpp"

Vulture::Vulture(double health, double speed, double attackStrength, int level, LevelStrategy* levelUpStrategy) {
    setName("Vulture");
    setDescription("Known for feasting on its foes.  A predator of the skies and land.");
    setType(flying);
    setSpeed(speed);
    setLevelUpStrategy(levelUpStrategy);
    setLevel(level);
    setMaxHealth(health);
    setHealth(health);
    setAttackStrength(attackStrength);   
    vector<AttackStrategy*> newAttacks = {new Flying(), new Kick(), new Tackle(), new Scratch()};
    setAttacks(newAttacks);
    setToPokeman(true);
}
/*
Vulture::~Vulture(){
	Character::~Character();
}*/
