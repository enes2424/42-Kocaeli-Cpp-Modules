#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void) {
	Bureaucrat	bureaucrat("Enes", 2);
	//SHRUBBERY_CREATION_FORM
	{
		AForm	*shrubberyCreationForm = new ShrubberyCreationForm("42Kocaeli");

		std::cout << *shrubberyCreationForm << std::endl;

		try {
			shrubberyCreationForm->execute(bureaucrat); //Form needs to be signed before executing
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}

		std::cout << std::endl;
		shrubberyCreationForm->beSigned(bureaucrat);
		std::cout << std::endl << *shrubberyCreationForm << std::endl;

		try {
			Bureaucrat	bureaucrat("Enes", 150);
			shrubberyCreationForm->execute(bureaucrat); //Grade too low exception
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}

		std::cout << std::endl;

		shrubberyCreationForm->execute(bureaucrat);
		delete shrubberyCreationForm;
	}
	//ROBOTOMY_REQUEST_FORM
	{
		AForm	*robotomyRequestForm = new RobotomyRequestForm("42Kocaeli");
		robotomyRequestForm->beSigned(bureaucrat);
		std::cout << std::endl;
		robotomyRequestForm->execute(bureaucrat);
		std::cout << std::endl;
		delete robotomyRequestForm;
	}

	//PRESIDENTIAL_PARDON_FORM
	{
		AForm	*presidentialPardonForm = new PresidentialPardonForm("42Kocaeli");
		presidentialPardonForm->beSigned(bureaucrat);
		std::cout << std::endl;
		presidentialPardonForm->execute(bureaucrat);
		std::cout << std::endl;
		delete presidentialPardonForm;
	}
	RobotomyRequestForm robotomyRequestForm("42Kocaeli");
	bureaucrat.executeForm(robotomyRequestForm);
	robotomyRequestForm.beSigned(bureaucrat);
	std::cout << std::endl;
	bureaucrat.executeForm(robotomyRequestForm);
	return 0;
}
