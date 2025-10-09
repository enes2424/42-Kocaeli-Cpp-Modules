#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : target("default"), AForm("presidential pardon", 25, 5) {
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : target(target), AForm("presidential pardon", 25, 5) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) {
	*this = other;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	set(other);
	const_cast<std::string &>(target) = other.target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
}

void		PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (!getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeRequiredToExecute())
		throw GradeTooLowException();
	std::cout << getName() << " is executed" << std::endl << std::endl;
	std::cout << target << "was pardoned by Zaphod Beeblebrox" << std::endl;
}
