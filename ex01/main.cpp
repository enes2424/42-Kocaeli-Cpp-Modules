#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete	meta;
	delete	j;
	delete	i;

	std::cout << std::endl << "~~~~WRONG~~~~" << std::endl << std::endl;

	const WrongAnimal* k = new WrongCat();

	std::cout << k->getType() << " " << std::endl;
	k->makeSound(); //will output the wronganimal sound!

	delete	k;

	std::cout << std::endl << "~~~~IDontWantToSetTheWorldOnFire~~~~" << std::endl << std::endl;

	Animal	*animals[8];

	for (int i = 0; i < 4; i++)
		animals[i] = new Dog();

	for (int i = 4; i < 8; i++)
		animals[i] = new Cat();

	for (int i = 0; i < 8; i++)
		delete animals[i];

	return 0;
}
