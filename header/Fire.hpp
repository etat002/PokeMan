#ifndef __fire_hpp__
#define __fire_hpp__
#include<iostream>
#include<string>
using namespace std;
#include"AttackStrategy.hpp"

class Fire : public AttackStrategy {
private:
	double power = 0.6;
	string name = "Fire Punch";
public: 
	virtual string getAtkName() {return name;};
	virtual double getAtk(){return power;};
};
#endif
