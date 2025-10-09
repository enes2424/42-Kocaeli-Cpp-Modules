#include "AMateria.hpp"

AMateria::AMateria(void) {
}

AMateria::AMateria(AMateria const &copy) {
    *this = copy;
}

AMateria::AMateria(std::string const &type) {
    int len = type.length();
    for (int i = 0; i < len; i++)
        this->type += std::tolower(type[i]);
}

AMateria   &AMateria::operator=(AMateria const &other) {
    type = other.type;
    return *this;
}

AMateria::~AMateria(void) {
}

std::string const &AMateria::getType() const {
    return type;
}

void    AMateria::use(ICharacter& target) {
    (void)target;
    std::cout << "* there is not use function your class *" << std::endl;
}
