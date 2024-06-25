#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include <string>
#include <vector>
#include "characterEntity.h"
#include "levelStrategy.h"
#include "AttackStrategy.hpp"

using namespace std;

enum Type {fire, grass, water, electric, rock, fighting, flying, dark, psychic, steel};

class Character: public CharacterEntity {
private:
    string description;
    Type type;

    double maxHealth;
    double health;
    double speed;
    double attackStrength;
    int level;
    int experience;
    bool isCaught;
    
    LevelStrategy* levelUpStrategy;
    vector<AttackStrategy*> attacks;
public:
    Character();
    virtual ~Character();
    void setDescription(string);
    void setType(Type);
    void setMaxHealth(double);
    void setHealth(double);
    void setAttackStrength(double);
    void setLevel(int);
    void setSpeed(double);
    void setLevelUpStrategy(LevelStrategy*);
    void setAttacks(vector<AttackStrategy*>&);
    void setExperience(int);
    void updateExperience();
    const string getDescription() const;
    const Type getType() const;
    const double getMaxHealth() const;
    const double getHealth() const;
    const double getSpeed() const;
    const double getAttackStrength() const;
    const int getLevel() const;
    const LevelStrategy* getLevelUpStrategy() const;
    const vector<AttackStrategy*>& getAttacks() const;
    const int getExperience() const;
    void levelUp();
    void setCaught(bool);
    const bool getCaught() const;
};

#endif
