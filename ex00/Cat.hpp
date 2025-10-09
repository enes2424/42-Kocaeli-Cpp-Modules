#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"

class Cat : public Animal {
	public:
		Cat(void);
		Cat(Cat &copy);
		Cat& operator=(Cat &other);
		~Cat(void);
		void	makeSound(void) const;
};

#endif
