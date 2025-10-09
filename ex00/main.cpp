#include "Bureaucrat.hpp"

int	main(void) {
	try {
		Bureaucrat	bureaucrat("Emir", 0);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat	bureaucrat("Eslem", 151);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	Bureaucrat	bureaucrat("Ebrar", 1);
	try {
		bureaucrat.increment();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	Bureaucrat	bureaucrat2("Azra", 150);
	try {
		bureaucrat2.decrement();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << bureaucrat << bureaucrat2;
	for (int i = 0; i < 74; i++)
		bureaucrat.decrement();
	std::cout << bureaucrat;
	return 0;
}
