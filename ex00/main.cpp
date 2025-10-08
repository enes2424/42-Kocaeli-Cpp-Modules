#include "Zombie.hpp"

int main(void)
{
	std::cout << " ----->> Stack Memory <<-----" << std::endl;
	Zombie first_zombie("Necmettin");
	first_zombie.announce();
	randomChump("Husamettin");
	std::cout << " ----->> Heap Memory <<-----" << std::endl;
	Zombie* second_zombie = newZombie("Fahriye");
	second_zombie->announce();
	delete second_zombie;
	return 0;
}
