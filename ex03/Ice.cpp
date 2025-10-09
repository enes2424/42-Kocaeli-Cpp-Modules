#include "Ice.hpp"

Ice::Ice(void) : AMateria("ICE") {
}

Ice::Ice(Ice const &copy) : AMateria(copy){
    *this = copy;
}

Ice   &Ice::operator=(Ice const &other) {
    (void)other;
    return *this;
}

Ice::~Ice(void) {
}

AMateria*   Ice::clone() const {
    return new Ice(*this);
}

void    Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
