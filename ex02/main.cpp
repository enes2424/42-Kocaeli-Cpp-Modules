#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	FragTrap john("John Doe");
	FragTrap idiot(john);
	ScavTrap chuck("Chuck Norris");
	FragTrap enes("Enes");
	FragTrap foreign;
	foreign = enes;

	john.attack("Chuck Norris");
	chuck.takeDamage(john.getAttackDamage());
	chuck.attack("Me");
	chuck.guardGate();
	chuck.beRepaired(20);
	chuck.takeDamage(100);
	foreign.attack("John Doe");
	john.takeDamage(foreign.getAttackDamage());
	foreign.highFivesGuys();
	return 0;
}
