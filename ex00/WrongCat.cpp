#include "WrongCat.hpp"

WrongCat::WrongCat(void) {
	std::cout << "WrongCat Default Constructor called" << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(WrongCat &copy) : WrongAnimal(copy) {
	std::cout << "WrongCat Copy Constructor called" << std::endl;
	*this = copy;
}

WrongCat &WrongCat::operator=(WrongCat &other) {
	type = other.type;
	return *this;
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat Destructor called" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << type << " meows" << std::endl;
}
