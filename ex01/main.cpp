#include "ScavTrap.hpp"

int	main()
{
	ScavTrap john("John Doe");
	ScavTrap idiot(john);
	ScavTrap chuck("Chuck Norris");
	ScavTrap foreign;
	foreign = chuck;

	john.attack("Chuck Norris");
	chuck.takeDamage(john.getAttackDamage());
	chuck.attack("Me");
	chuck.guardGate();
	chuck.beRepaired(20);
	chuck.takeDamage(10);
	foreign.attack("John Doe");
	john.takeDamage(foreign.getAttackDamage());
	return 0;
}
