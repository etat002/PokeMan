#include<iostream>
#include<string>
#include"AttackStrategy.hpp"
using namespace std;

class Kick : public AttackStrategy {
private:
	double power = 0.2;
	string name = "Kick";
public:
	virtual string getAtkName() { return name;}
	virtual double getAtk()  {return power;}
};

