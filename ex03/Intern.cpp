#include "Intern.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern &other) {*this = other;}

Intern	&Intern::operator=(const Intern &other) {return *this;}

Intern::~Intern(void) {}

AForm *Intern::makeForm(std::string name, std::string target) {
	int num = (name == "presidential pardon") + 2 * (name == "robotomy request") + 3 * (name == "shrubbery creation");

	switch (num) {
		case 1:
			std::cout << "Intern creates " << name << std::endl;
			return new PresidentialPardonForm(target);
		case 2:
			std::cout << "Intern creates " << name << std::endl;
			return new RobotomyRequestForm(target);
		case 3:
			std::cout << "Intern creates " << name << std::endl;
			return new ShrubberyCreationForm(target);
		default:
			std::cout << "Intern could not create a form!!" << std::endl;
			return NULL;
	}
}
