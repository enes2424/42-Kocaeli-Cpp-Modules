#include "AForm.hpp"

AForm::AForm(void) : name("default"), grade_required_to_sign(150), grade_required_to_execute(150) {
	is_signed = false;
}

AForm::AForm(const AForm &other) : grade_required_to_sign(150), grade_required_to_execute(150) {
	*this = other;
}

AForm::AForm(std::string name, int grade_required_to_sign, int grade_required_to_execute) : name(name), grade_required_to_sign(grade_required_to_sign), grade_required_to_execute(grade_required_to_execute) {
	is_signed = false;
	if (grade_required_to_sign < 1 || grade_required_to_execute < 1)
		throw GradeTooHighException();
	else if (grade_required_to_sign > 150 || grade_required_to_execute > 150)
		throw GradeTooLowException();
}

AForm	&AForm::operator=(const AForm &other) {
	const_cast<std::string &>(name) = other.name;
	is_signed = other.is_signed;
	const_cast<int &>(grade_required_to_sign) = other.grade_required_to_sign;
	const_cast<int &>(grade_required_to_execute) = other.grade_required_to_execute;
	return *this;
}

AForm::~AForm(void) {
}

const std::string	&AForm::getName(void) const {
	return name;
}

const int			AForm::getGradeRequiredToSign(void) const {
	return grade_required_to_sign;
}

const int			AForm::getGradeRequiredToExecute(void) const {
	return grade_required_to_execute;
}

bool				AForm::getIsSigned(void) const {
	return is_signed;
}

void				AForm::set(const AForm &other) {
	*this = other;
}

void				AForm::beSigned(Bureaucrat &bureaucrat) {
	if (is_signed) {
		std::cout << name << " has already been signed by a bureaucrat" << std::endl;
		return ;
	}
	if (bureaucrat.getGrade() <= grade_required_to_sign)
		is_signed = true;
	bureaucrat.signForm(*this);
	if (bureaucrat.getGrade() > grade_required_to_sign)
		throw GradeTooLowException();
}

const char*	AForm::GradeTooHighException::what() const throw() {
	return "Grade too high exception";
}

const char*	AForm::GradeTooLowException::what() const throw() {
	return "Grade too low exception";
}

const char *AForm::FormNotSignedException::what(void) const throw()
{
	return ("Form needs to be signed before executing");
};

std::ostream	&operator<<(std::ostream &o, const AForm &form) {
	o << form.getName() << ", form ";
	if (form.getIsSigned())
		o << "is signed";
	else
		o << "is not signed";
	o << ", form sign grade " << form.getGradeRequiredToSign()
		<< ", form execute grade "
		<< form.getGradeRequiredToExecute() << "." << std::endl;
	return o;
}
