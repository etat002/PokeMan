#ifndef __attackStrategy_hpp__
#define __attackStrategy_hpp__
#include<iostream>
#include<string>
using namespace std;
class AttackStrategy {
private:
	double AtkPower;
	string name;
public:
        virtual ~AttackStrategy() {}
	virtual double getAtk()= 0;
	virtual string getAtkName() = 0;
};
#endif

