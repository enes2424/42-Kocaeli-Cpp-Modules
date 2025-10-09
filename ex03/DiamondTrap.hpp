#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
    private:
        string name;
    public:
        DiamondTrap& operator=(DiamondTrap &other);
        DiamondTrap(void);
		DiamondTrap(string name);
		DiamondTrap(DiamondTrap &copy);
        ~DiamondTrap(void);
		void	attack(const string& target);
		string	getPrivateName();
        void    whoAmI(void);
};

#endif
