#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>
#define string std::string
#define cout std::cout
#define endl std::endl

class ClapTrap {
	protected:
		string		name;
		int			hit_points;
		int			energy_points;
		int			attack_damage;

	public:
		ClapTrap& operator=(ClapTrap &other);
		ClapTrap(void);
		ClapTrap(string name);
		ClapTrap(ClapTrap &copy);
		~ClapTrap(void);
		void		attack(const string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		string		getName(void);
		int			getHitPoints(void);
		int			getEnergyPoints(void);
		int			getAttackDamage(void);
};

#endif
