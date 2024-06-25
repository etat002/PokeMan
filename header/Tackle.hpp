#include<iostream>
#include<string>
#include"AttackStrategy.hpp"
using namespace std;

class Tackle : public AttackStrategy {
private:
	double power = 0.2;
	string name = "Tackle";
public:

	virtual string getAtkName() { return name;}
	virtual double getAtk()  {return power;}
};

