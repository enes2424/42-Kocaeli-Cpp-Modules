#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
    public:
        FragTrap& operator=(FragTrap &other);
        FragTrap(void);
		FragTrap(string name);
		FragTrap(FragTrap &copy);
        ~FragTrap(void);
        void    highFivesGuys(void);
};

#endif
