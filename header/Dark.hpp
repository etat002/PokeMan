#ifndef __dark_hpp__
#define __dark_hpp__
#include<iostream>
#include<string>
#include"AttackStrategy.hpp"
using namespace std;

class Dark: public AttackStrategy {
private:
	double power = 0.6;
	string name = "Dark Punch";
public:
	virtual string getAtkName() { return name;}
	virtual double getAtk()  {return power;}
};
#endif
