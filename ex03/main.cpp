#include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap john("John Doe");
	DiamondTrap idiot(john);
	DiamondTrap chuck("Chuck Norris");
	DiamondTrap enes("Enes");
	DiamondTrap foreign;
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
	john.whoAmI();
	idiot.whoAmI();
	chuck.whoAmI();
	enes.whoAmI();
	foreign.whoAmI();
	return 0;
}
