#include "Zombie.hpp"

Zombie::Zombie(void)
{
}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie(void)
{
	std::cout << name << " died!" << std::endl;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}
