#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) {
	cout << "DiamondTrap Default Constructor called" << endl;
}

DiamondTrap::DiamondTrap(string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
	cout << "DiamondTrap Name Constructor called" << endl;
    this->name = name;
	hit_points = FragTrap::hit_points;
	energy_points = ScavTrap::energy_points;
	attack_damage = FragTrap::attack_damage;
}

DiamondTrap::DiamondTrap(DiamondTrap &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy) {
	cout << "DiamondTrap Copy Constructor called" << endl;
    *this = copy;
}

DiamondTrap::~DiamondTrap(void) {
	cout << "DiamondTrap Destructor called" << endl;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap &other) {
	cout << "DiamondTrap Copy Assignment called" << endl;
	ClapTrap::name = other.getName();
	this->name = other.getPrivateName();
	hit_points = other.getHitPoints();
	energy_points = other.getEnergyPoints();
	attack_damage = other.getAttackDamage();
	return *this;
}

void	DiamondTrap::attack(const string& target) {
	ScavTrap::attack(target);
}

string	DiamondTrap::getPrivateName() {
	return name;
}

void    DiamondTrap::whoAmI(void) {
	cout << "Name : " << name << ", ClapTrap Name : " << ClapTrap::name << endl;
}
