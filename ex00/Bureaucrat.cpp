#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name("default") {
	grade = 150;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) {
	*this = other;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other) {
	const_cast<std::string &>(name) = other.name;
	grade = other.grade;
	return *this;
}

Bureaucrat::~Bureaucrat(void) {
}

const std::string	&Bureaucrat::getName(void) const {
	return name;
}

int	Bureaucrat::getGrade(void) const {
	return grade;
}

void	Bureaucrat::increment(void) {
	if (grade - 1 < 1)
		throw GradeTooHighException();
	grade--;
}

void	Bureaucrat::decrement(void) {
	if (grade + 1 > 150)
		throw GradeTooLowException();
	grade++;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high exception";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low exception";
}

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &bureaucrat) {
	o << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
	return o;
}
