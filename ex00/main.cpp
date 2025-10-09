#include "ClapTrap.hpp"

int	main()
{
	ClapTrap john("John Doe");
	ClapTrap chuck("Chuck Norris");
	ClapTrap foreign;
	foreign = chuck;

	john.attack("Chuck Norris");
	chuck.takeDamage(john.getAttackDamage());
	chuck.takeDamage(20);
	chuck.attack("Me");
	chuck.beRepaired(2);
	chuck.takeDamage(10);
	foreign.attack("John Doe");
	john.takeDamage(foreign.getAttackDamage());
	return 0;
}
