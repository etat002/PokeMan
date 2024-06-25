#ifndef __psychic_hpp__
#define __psychic_hpp__
#include<iostream>
#include<string>
#include"AttackStrategy.hpp"
using namespace std;

class Psychic : public AttackStrategy {
private:
	double power = 0.6;
	string name = "Psychic Punch";
public:
	virtual string getAtkName() { return name;}
	virtual double getAtk()  {return power;}
};
#endif
