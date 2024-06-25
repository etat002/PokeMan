#include <iostream>
#include "../header/character.h"
#include "../header/mediumLevel.h"

Character::Character(): description(""), type(water), maxHealth(0),
                        health(0), speed(0), attackStrength(0), level(1),
                        experience(0), levelUpStrategy(new MediumLevel()), isCaught(false) {}

Character::~Character() {
     delete levelUpStrategy;
     for(unsigned int i  = 0; i < attacks.size(); ++i) {
        delete attacks.at(i);
        attacks.at(i) = nullptr;
    }
}

void Character::setDescription(string newDescription) {
    description = newDescription;
}

void Character::setType(Type newType) {
    type = newType;
}

void Character::setMaxHealth(double newHealth) {
    if(newHealth >= 0) {
        if(newHealth > maxHealth) {
            maxHealth = newHealth;
        }
    }
}

void Character::setHealth(double newHealth) {
    if(newHealth >= 0) {
        if(newHealth <= maxHealth) {
            health = newHealth;
        }
        else {
            health = maxHealth;
        }
    }
    else {
        health = 0;
    }
}

void Character::setAttackStrength(double newStrength) {
    attackStrength = newStrength;
}

void Character::setLevel(int newLevel) {
    if(newLevel > 0) {
        if(newLevel > level) {
            while(level < newLevel) {
                setExperience(experience + 5);
            }
        }
    }
}

void Character::setSpeed(double newSpeed) {
    speed = newSpeed;
}

void Character::setLevelUpStrategy(LevelStrategy* newStrategy) {
    if(newStrategy != nullptr) {
        if(levelUpStrategy != nullptr) { 
            delete levelUpStrategy;
        }
        levelUpStrategy = newStrategy;
    }
}

void Character::setAttacks(vector<AttackStrategy*>& newAttacks) {
    for(unsigned int i = 0; i < attacks.size(); ++i) {
        delete attacks.at(i);
    }

    if(attacks.size() > 0) {
        for(unsigned int i = attacks.size() - 1; i >= 0; --i) {
            attacks.pop_back();
        }
    }

    for(unsigned int i = 0; i < newAttacks.size(); ++i) {
        attacks.push_back(newAttacks.at(i));
    }
}

void Character::setExperience(int newExperience) {
    if(newExperience > experience) {
        while(newExperience >= levelUpStrategy->getExpCap()) {
            levelUp();
        }
        experience = newExperience;
    }
}

void Character::updateExperience() {
    setExperience(experience + 5);
}

const string Character::getDescription() const {
    return description;
}

const Type Character::getType() const {
    return type;
}

const double Character::getMaxHealth() const {
    return maxHealth;
}

const double Character::getHealth() const {
    return health;
}

const double Character::getSpeed() const {
    return speed;
}

const double Character::getAttackStrength() const {
    return attackStrength;
}

const int Character::getLevel() const {
    return level;
}

const LevelStrategy* Character::getLevelUpStrategy() const {
    return levelUpStrategy;
}

const vector<AttackStrategy*>& Character::getAttacks() const {
    return attacks;
}

const int Character::getExperience() const {
    return experience;
}

void Character::levelUp() {
    ++level;
    levelUpStrategy->setExpCap();
    maxHealth += 1;
    attackStrength += 1;
    std::cout << std::endl << getName() << " has leveled up." << std::endl << std::endl;
}

void Character::setCaught(bool caught) {
    isCaught = caught;
}

const bool Character::getCaught() const {
    return isCaught;
}
