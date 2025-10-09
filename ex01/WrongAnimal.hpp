#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <iostream>

class WrongAnimal {
	protected:
		std::string	type;
	public:
		WrongAnimal(void);
		WrongAnimal(WrongAnimal &copy);
		WrongAnimal& operator=(WrongAnimal &other);
		~WrongAnimal(void);
		std::string		getType(void)	const;
		void	makeSound(void) const;
};

#endif
