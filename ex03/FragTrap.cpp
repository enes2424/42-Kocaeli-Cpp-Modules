#include "FragTrap.hpp"

FragTrap::FragTrap(void) {
	cout << "FragTrap Default Constructor called" << endl;
}

FragTrap::FragTrap(string name) : ClapTrap(name) {
	cout << "FragTrap Name Constructor called" << endl;
}

FragTrap::FragTrap(FragTrap &copy) : ClapTrap(copy) {
	cout << "FragTrap Copy Constructor called" << endl;
	*this = copy;
}

FragTrap::~FragTrap(void) {
	cout << "FragTrap Destructor called" << endl;
}

FragTrap& FragTrap::operator=(FragTrap &other) {
	cout << "FragTrap Copy Assignment called" << endl;
	name = other.getName();
	hit_points = other.getHitPoints();
	energy_points = other.getEnergyPoints();
	attack_damage = other.getAttackDamage();
	return *this;
}

void    FragTrap::highFivesGuys(void) {
	cout << "FragTrap " << name << " say high fives guys" << endl;
}
