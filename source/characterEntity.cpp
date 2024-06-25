#include "../header/characterEntity.h"

const string CharacterEntity::getName() const {
    return name;
}

const bool CharacterEntity::getIfPokeman() const {
    return pokeman;
}

void CharacterEntity::setName(string newName) {
    name = newName;
}

void CharacterEntity::setToPokeman(bool set) {
    pokeman = set;
}
