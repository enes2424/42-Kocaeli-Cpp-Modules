#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    public:
        ScavTrap& operator=(ScavTrap &other);
        ScavTrap(void);
		ScavTrap(string name);
		ScavTrap(ScavTrap &copy);
        ~ScavTrap(void);
        void	attack(const string& target);
        void    guardGate(void);
};

#endif
