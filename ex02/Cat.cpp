#include "Cat.hpp"

Cat::Cat(void) {
	std::cout << "Cat Default Constructor called" << std::endl;
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(Cat &copy) : Animal(copy) {
	std::cout << "Cat Copy Constructor called" << std::endl;
	*this = copy;
}

Cat &Cat::operator=(Cat &other) {
	type = other.type;
	*brain = *other.brain;
	return *this;
}

Cat::~Cat(void) {
	delete	brain;
	std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << type << " meows" << std::endl;
}
