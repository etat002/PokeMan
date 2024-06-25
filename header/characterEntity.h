#ifndef _CHARACTERENTITY_H_
#define _CHARACTERENTITY_H_

#include <string>

using namespace std;

class CharacterEntity {
private:
    string name;
    bool pokeman;
public:
    const string getName() const;
    const bool getIfPokeman() const;
    void setName(string);
    void setToPokeman(bool);
};

#endif
