#include "ClapTrap.hpp"
#define cout std::cout
#define endl std::endl

ClapTrap& ClapTrap::operator=(ClapTrap &other) {
	cout << "Copy Assignment called" << endl;
	name = other.getName();
	hit_points = other.getHitPoints();
	energy_points = other.getEnergyPoints();
	attack_damage = other.getAttackDamage();
	return *this;
}

ClapTrap::ClapTrap(void) {
	cout << "Default Constructor called" << endl;
}

ClapTrap::ClapTrap(std::string name) {
	cout << "Name Constructor called" << endl;
	this->name = name;
	hit_points = 10;
	energy_points = 10;
	attack_damage = 0;
}

ClapTrap::ClapTrap(ClapTrap &copy) {
	cout << "Copy Constructor called" << endl;
	*this = copy;
}

ClapTrap::~ClapTrap(void) {
	cout << "Destructor called" << endl;
}

void	ClapTrap::attack(const std::string& target) {
	if (!energy_points)
	{
		cout << "ClapTrap " << name << " can't attack " << target << " because it runs out of energy points" << endl;
		return ;
	}
	cout << "ClapTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << endl;
	energy_points--;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	unsigned int tmp;

	if (static_cast<unsigned int>(hit_points) < amount) {
		tmp = static_cast<unsigned int>(hit_points);
		hit_points = 0;
	} else {
		hit_points -= amount;
		tmp = amount;
	}
	cout << "ClapTrap " << name << " takes " << tmp << " points of damage!" << endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (!energy_points)
	{
		cout << "ClapTrap " << name << " can't repair itself because it runs out of energy points" << endl;
		return ;
	}
	hit_points += amount;
	cout << "ClapTrap " << name << " repairs " << amount << " points" << endl;
	energy_points--;
}

std::string	ClapTrap::getName(void) {
	return name;
}

int	ClapTrap::getHitPoints(void) {
	return hit_points;
}

int	ClapTrap::getEnergyPoints(void) {
	return energy_points;
}

int	ClapTrap::getAttackDamage(void) {
	return attack_damage;
}
