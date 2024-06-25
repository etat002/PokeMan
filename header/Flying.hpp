#ifndef __flying_hpp__
#define __flying_hpp__
#include<iostream>
#include<string>
#include"AttackStrategy.hpp"
using namespace std;

class Flying : public AttackStrategy {
private:
	double power = 0.6;
	string name = "Flying Punch";
public:
        string getAtkName() { return name;} 
	double getAtk()  {return power;}
};
#endif
