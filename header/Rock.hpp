#ifndef __rock_hpp__
#define __rock_hpp__
#include<iostream>
#include<string>
#include"AttackStrategy.hpp"
using namespace std;

class Rock : public AttackStrategy {
private:
	double power = 0.6;
	string name = "Rock Punch";
public:
	virtual string getAtkName() { return name;}
	virtual double getAtk()  {return power;}
};
#endif

