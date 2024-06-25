#ifndef __Item_hpp__
#define __Item_hpp__

#include <string>
#include <iostream>
#include "character.h"
#include "pokehub.h"

using namespace std;

class Item {
private:
	string description;
	string name;
        bool pokesphere;
public:
	virtual ~Item(){}
	virtual void action(Character* x,ostream& p, Pokehub* t) = 0;
	const string getName() const {return name;}
	const string getDescription() const {return description;}
        void setName(std::string name) {
        	this->name = name;
        }
        void setDescription(std::string description) {
		this->description = description;
        }
        void setPokesphere(bool set) {
		pokesphere = set;
	}
	bool getIfPokesphere() {
		return pokesphere;
	}
};

#endif
