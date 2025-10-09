#include "Animal.hpp"

Animal::Animal(void) {
	std::cout << "Animal Default Constructor called" << std::endl;
	type = "Animal";
}

Animal::Animal(Animal &copy) {
	std::cout << "Animal Copy Constructor called" << std::endl;
	*this = copy;
}

Animal &Animal::operator=(Animal &other) {
	type = other.type;
	return *this;
}

Animal::~Animal(void) {
	std::cout << "Animal Destructor called" << std::endl;
}

std::string	Animal::getType(void) const{
	return type;
}
