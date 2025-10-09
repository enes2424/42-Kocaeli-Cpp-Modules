#include "Intern.hpp"

int	main(void) {
	Intern		someRandomIntern;
	Bureaucrat	bureaucrat("Enes", 4);
	AForm*		rrf;
	std::string	arr[] = {"presidential pardon", "robotomy request", "shrubbery creation", "form mor fdsfsd"};

	int	i;
	for (i = 0; i < 4; i++)
	{
		rrf = someRandomIntern.makeForm(arr[i], "Bender");
		if (rrf)
		{
			try {
				rrf->beSigned(bureaucrat);
			} catch (std::exception &e) {
				std::cout << std::endl << e.what() << std::endl;
			}
			try {
				rrf->execute(bureaucrat);
			} catch (std::exception &e) {
				std::cout << std::endl << e.what() << std::endl << std::endl;
			}
			delete rrf;
		}
	}
	return 0;
}
