#ifndef __fighting_hpp__
#define __fighting_hpp__
#include<iostream>
#include<string>
#include"AttackStrategy.hpp"
using namespace std;

class Fighting : public AttackStrategy {
private:
	double power = 0.6;
	string name = "Fighting Punch";
public:

	virtual string getAtkName() { return name;}
	virtual double getAtk()  {return power;}
};
#endif
