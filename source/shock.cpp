#include <cstdlib>
#include <ctime>
#include "../header/shock.h"
#include "../header/Electric.hpp"
#include "../header/Kick.hpp"
#include "../header/Tackle.hpp"
#include "../header/Scratch.hpp"

Shock::Shock(double health, double speed, double attackStrength, int level, LevelStrategy* levelUpStrategy) {
    setName("Shock");
    setDescription("They say if you could harness the power from this pokeman you could power a large city.  Be aware when crossing its path.");
    setType(electric);
    setSpeed(speed);
    setLevelUpStrategy(levelUpStrategy);
    setLevel(level);
    setMaxHealth(health);
    setHealth(health);
    setAttackStrength(attackStrength);
    vector<AttackStrategy*> newAttacks = {new Electric(), new Kick(), new Tackle(), new Scratch()};
    setAttacks(newAttacks);
    setToPokeman(true);
}

/*
Shock::~Shock() {

}*/
