#include "Dog.hpp"

Dog::Dog(void) {
	std::cout << "Dog Default Constructor called" << std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(Dog &copy) : Animal(copy) {
	std::cout << "Dog Copy Constructor called" << std::endl;
	*this = copy;
}

Dog &Dog::operator=(Dog &other) {
	type = other.type;
	*brain = *other.brain;
	return *this;
}

Dog::~Dog(void) {
	delete brain;
	std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << type << " barks" << std::endl;
}
