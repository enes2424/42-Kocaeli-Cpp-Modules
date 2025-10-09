#include "Cat.hpp"

Cat::Cat(void) {
	std::cout << "Cat Default Constructor called" << std::endl;
	type = "Cat";
}

Cat::Cat(Cat &copy) : Animal(copy) {
	std::cout << "Cat Copy Constructor called" << std::endl;
	*this = copy;
}

Cat &Cat::operator=(Cat &other) {
	type = other.type;
	return *this;
}

Cat::~Cat(void) {
	std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << type << " meows" << std::endl;
}
