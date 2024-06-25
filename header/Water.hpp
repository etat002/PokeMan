#ifndef __water_hpp__
#define __water_hpp__
#include<iostream>
#include<string>
#include"AttackStrategy.hpp"
using namespace std;

class Water : public AttackStrategy {
private:
	double power = 0.6;
	string name = "Water Punch";
public:
	virtual string getAtkName() { return name;}
	virtual double getAtk()  {return power;}
};
#endif
