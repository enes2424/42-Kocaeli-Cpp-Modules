#ifndef FORM
#define FORM
#include "Bureaucrat.hpp"

class Form {
	public:
		Form(void);
		Form(const Form &other);
		Form(std::string name, int grade_required_to_sign, int grade_required_to_execute);
		Form	&operator=(const Form &other);
		~Form(void);
		const std::string	&getName(void) const;
		const int			getGradeRequiredToSign(void) const;
		const int			getGradeRequiredToExecute(void) const;
		bool				getIsSigned(void) const;
		void				beSigned(Bureaucrat &bureaucrat);
		class	GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class	GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
	private:
		const std::string	name;
		const int			grade_required_to_sign;
		const int			grade_required_to_execute;
		bool				is_signed;
};

std::ostream	&operator<<(std::ostream &o, const Form &form);

#endif
