#include "Form.hpp"

int	main(void) {
	try {
		Form	form("Turk Form", -10, 80);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	Form	form("Turk Form", 20, 80);
	std::cout << form;
	try {
		Bureaucrat bureaucrat("Jhonny", 30);
		form.beSigned(bureaucrat);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	Bureaucrat bureaucrat("Enes", 10);
	form.beSigned(bureaucrat);
	std::cout << form;
	Bureaucrat bureaucrat2("Emir", 5);
	form.beSigned(bureaucrat2);
	return 0;
}
