#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Brain Default Constructor called" << std::endl;
	ideas = new std::string[100];
}

Brain::Brain(Brain &copy) {
	std::cout << "Brain Copy Constructor called" << std::endl;
	*this = copy;
}

Brain &Brain::operator=(Brain &other) {
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
	return *this;
}

Brain::~Brain(void) {
	delete[] ideas;
	std::cout << "Brain Destructor called" << std::endl;
}
