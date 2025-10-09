#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		WrongCat(void);
		WrongCat(WrongCat &copy);
		WrongCat& operator=(WrongCat &other);
		~WrongCat(void);
		void	makeSound(void) const;
};

#endif
