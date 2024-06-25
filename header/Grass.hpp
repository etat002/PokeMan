#ifndef __grass_hpp__
#define __grass_hpp__
#include<iostream>
#include<string>
#include"AttackStrategy.hpp"
using namespace std;

class Grass : public AttackStrategy {
private:
	double power = 0.6;
	string name = "Grass Punch";
public:
	virtual string getAtkName() { return name;}
	virtual double getAtk()  {return power;}
};
#endif
