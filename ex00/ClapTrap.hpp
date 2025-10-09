#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>

class ClapTrap {
	private:
		std::string	name;
		int			hit_points;
		int			energy_points;
		int			attack_damage;

	public:
		ClapTrap& operator=(ClapTrap &other);
		ClapTrap(std::string name);
		ClapTrap(void);
		ClapTrap(ClapTrap &copy);
		~ClapTrap(void);
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		std::string	getName(void);
		int			getHitPoints(void);
		int			getEnergyPoints(void);
		int			getAttackDamage(void);
};

#endif
