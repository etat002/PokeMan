#ifndef __steel_hpp__
#define __steel_hpp__
#include<iostream>
#include<string>
#include"AttackStrategy.hpp"
using namespace std;

class Steel : public AttackStrategy {
private:
	double power = 0.6;
	string name = "Steel Punch";
public:
	virtual string getAtkName() { return name;}
	virtual double getAtk()  {return power;}
};
#endif
