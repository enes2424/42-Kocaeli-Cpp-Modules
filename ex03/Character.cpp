#include "Character.hpp"

Character::Character(void) {
    materias = new AMateria*[4];
    for (int i = 0; i < 4; i++)
        materias[i] = NULL;
}

Character::Character(std::string const &name) {
    materias = new AMateria*[4];
    for (int i = 0; i < 4; i++)
        materias[i] = NULL;
    this->name = name;
}

Character::Character(Character &copy) {
    materias = new AMateria*[4];
    for (int i = 0; i < 4; i++)
        materias[i] = NULL;
    *this = copy;
}

Character& Character::operator=(Character const &other) {
    for (int i = 0; i < 4; i++)
        if (other.materias[i])
            *materias[i] = *other.materias[i];
    return *this;
}

Character::~Character(void) {
    for (int i = 0; i < 4; i++)
        if (materias[i])
            delete materias[i];
    delete[] materias;
}

std::string const & Character::getName() const {
    return name;
}

void Character::equip(AMateria* m) {
    int i;
    for (i = 0; i < 4; i++)
        if (!materias[i])
            break;
    if (i == 4)
        return;
    materias[i] = m;
}

void Character::unequip(int idx) {
    if (idx < 0 || idx > 3)
        return;
    materias[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
    if (materias[idx])
        materias[idx]->use(target);
}
