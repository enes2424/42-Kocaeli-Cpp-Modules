#ifndef INTERN
#define INTERN

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	public:
		Intern(void);
		Intern(const Intern &other);
		Intern	&operator=(const Intern &other);
		~Intern(void);
		AForm *makeForm(std::string name, std::string target);
};

#endif
