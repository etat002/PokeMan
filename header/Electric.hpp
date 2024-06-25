#ifndef __electric_hpp__
#define __electric_hpp__
#include<iostream>
#include<string>
#include"AttackStrategy.hpp"
using namespace std;

class Electric : public AttackStrategy {
private:
	double power = 0.6;
	string name = "Electric Punch";
public:
	virtual string getAtkName() { return name;}
	virtual double getAtk()  {return power;}
};
#endif

