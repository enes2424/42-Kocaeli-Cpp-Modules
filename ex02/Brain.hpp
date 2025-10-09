#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>

class Brain {
	private:
		std::string *ideas;

	public:
		Brain(void);
		Brain(Brain &copy);
		Brain& operator=(Brain &other);
		~Brain(void);
};

#endif
