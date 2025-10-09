#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>

class Animal {
	protected:
		std::string	type;
	public:
		Animal(void);
		Animal(Animal &copy);
		Animal& operator=(Animal &other);
		virtual 		~Animal(void);
		std::string		getType(void)	const;
		virtual void	makeSound(void) const = 0;
};

#endif
