#include <cstdlib>
#include <ctime>
#include "../header/tidal.h"
#include "../header/Water.hpp"
#include "../header/Kick.hpp"
#include "../header/Tackle.hpp"
#include "../header/Scratch.hpp"

Tidal::Tidal(double health, double speed, double attackStrength, int level, LevelStrategy* levelUpStrategy) {
    setName("Tidal");
    setDescription("You may see this pokeman miles away.  Run!  It leaves a pile of wreakage in its wake.");
    setType(water);
    setSpeed(speed);
    setLevelUpStrategy(levelUpStrategy);
    setLevel(level);
    setMaxHealth(health);
    setHealth(health);
    setAttackStrength(attackStrength);
    vector<AttackStrategy*> newAttacks = {new Water(), new Kick(), new Tackle(), new Scratch()};
    setAttacks(newAttacks);
    setToPokeman(true);
}
