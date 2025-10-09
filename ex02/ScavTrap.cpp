#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) {
	cout << "ScavTrap Default Constructor called" << endl;
}

ScavTrap::ScavTrap(string name) : ClapTrap(name) {
	cout << "ScavTrap Name Constructor called" << endl;
}

ScavTrap::ScavTrap(ScavTrap &copy) : ClapTrap(copy) {
	cout << "ScavTrap Copy Constructor called" << endl;
	*this = copy;
}

ScavTrap::~ScavTrap(void) {
	cout << "ScavTrap Destructor called" << endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap &other) {
	cout << "ScavTrap Copy Assignment called" << endl;
	name = other.getName();
	hit_points = other.getHitPoints();
	energy_points = other.getEnergyPoints();
	attack_damage = other.getAttackDamage();
	return *this;
}

void	ScavTrap::attack(const string& target) {
	if (!energy_points)
	{
		cout << "ScavTrap " << name << " can't attack " << target << " because it runs out of energy points" << endl;
		return ;
	}
	cout << "ScavTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << endl;
	energy_points--;
}

void	ScavTrap::guardGate(void) {
	cout << "ScavTrap " << name << " activate gate keeper mode" << endl;
}
