#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : target("default"), AForm("shrubbery creation", 145, 137) {
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : target(target), AForm("shrubbery creation", 145, 137) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) {
	*this = other;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	set(other);
	const_cast<std::string &>(target) = other.target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
}

void		ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	if (!getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeRequiredToExecute())
		throw GradeTooLowException();
	std::cout << getName() << " is executed" << std::endl << std::endl;
	std::ofstream file(target + "_shrubbery", std::ios::trunc);
	if (!file.is_open()) {
		std::cout << "File is not opened" << std::endl;
		return ;
	}
	file << "\n\n          &&& &&  & &&                    ";
	file << "          &&& &&  & &&" << std::endl;
	file << "      && &\\/&\\|& ()|/ @, &&               ";
	file << "      && &\\/&\\|& ()|/ @, &&" << std::endl;
	file << "      &\\/(/&/&||/& /_/)_&/_&              ";
	file << "      &\\/(/&/&||/& /_/)_&/_&" << std::endl;
	file << "   &() &\\/&|()|/&\\/ '%\" & ()              ";
	file << "   &() &\\/&|()|/&\\/ '%\" & ()" << std::endl;
	file << "  &_\\_&&_\\ |& |&&/&__%_/_& &&             ";
	file << "  &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
	file << "&&   && & &| &| /& & % ()& /&&            ";
	file << "&&   && & &| &| /& & % ()& /&&" << std::endl;
	file << " ()&_---()&\\&\\|&&-&&--%---()~             ";
	file << " ()&_---()&\\&\\|&&-&&--%---()~" << std::endl;
	file << "     &&     \\|||                          ";
	file << "     &&     \\|||" << std::endl;
	file << "             |||                          ";
	file << "             |||" << std::endl;
	file << "             |||                          ";
	file << "             |||" << std::endl;
	file << "             |||                          ";
	file << "             |||" << std::endl;
	file << "       , -=-~  .-^- _                     ";
	file << "       , -=-~  .-^- _" << std::endl;
	file << "              `                           ";
	file << "              `" << std::endl << std::endl;
	file.close();
}
