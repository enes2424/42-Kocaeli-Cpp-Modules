#include "Base.hpp"
#include <cstdlib>
#include <ctime>

Base * generate(void) {
	std::srand(std::time(NULL));
	int	num = std::rand() % 3 + 1;
	switch (num)
	{
		case 1:
			return new A();
		case 2:
			return new B();
		default:
			return new C();
	}
}

void identify(Base* p) {
	if (!p)
	{
		std::cout << "NULL" << std::endl;
		return ;
	}
	A *a = dynamic_cast<A *>(p);
	if (a)
	{
		std::cout << "A" << std::endl;
		return ;
	}
	B *b = dynamic_cast<B *>(p);
	if (b)
	{
		std::cout << "B" << std::endl;
		return ;
	}
	C *c = dynamic_cast<C *>(p);
	if (c)
	{
		std::cout << "C" << std::endl;
		return ;
	}
	std::cout << "BASE" << std::endl;
	return ;
}

void identify(Base& p) {
	try {
		A& a = dynamic_cast<A& >(p);
		std::cout << "A" << std::endl;
		(void)a;
	} catch (std::exception &e) {
		try {
			B& b = dynamic_cast<B& >(p);
			std::cout << "B" << std::endl;
			(void)b;
		} catch (std::exception &e) {
			try {
				C& c = dynamic_cast<C& >(p);
				std::cout << "C" << std::endl;
				(void)c;
			} catch (std::exception &e) {
				Base &base = dynamic_cast<Base& >(p);
				std::cout << "BASE" << std::endl;
				(void)base;
			}
		}
	}
}
