#include "Cure.hpp"

Cure::Cure(void) : AMateria("CURE") {
}

Cure::Cure(Cure const &copy) : AMateria(copy) {
    *this = copy;
}

Cure   &Cure::operator=(Cure const &other) {
    type = other.type;
    return *this;
}

Cure::~Cure(void) {
}

AMateria*   Cure::clone() const {
    return new Cure(*this);
}

void    Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() <<  "'s wounds *" << std::endl;
}
