#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(void) : target("default"), AForm("robotomy request", 72, 45) {
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : target(target), AForm("robotomy request", 72, 45) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) {
	*this = other;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	set(other);
	const_cast<std::string &>(target) = other.target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
}

void		RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (!getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeRequiredToExecute())
		throw GradeTooLowException();
	std::cout << getName() << " is executed" << std::endl << std::endl;
	std::cout << "GIRRRRRRRRR" << std::endl;
	std::srand(std::time(NULL));
	if (std::rand() % 2 == 0)
		std::cout << target << " was robotomized " << std::endl;
	else
		std::cout << target << " was not robotomized " << std::endl;
}
