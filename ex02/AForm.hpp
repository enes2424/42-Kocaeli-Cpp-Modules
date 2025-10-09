#ifndef AFORM
#define AFORM
#include "Bureaucrat.hpp"

class AForm {
	public:
		AForm(void);
		AForm(const AForm &other);
		AForm(std::string name, int grade_required_to_sign, int grade_required_to_execute);
		AForm	&operator=(const AForm &other);
		virtual ~AForm(void);
		const std::string	&getName(void) const;
		const int			getGradeRequiredToSign(void) const;
		const int			getGradeRequiredToExecute(void) const;
		bool				getIsSigned(void) const;
		void				set(const AForm &other);
		void				beSigned(Bureaucrat &bureaucrat);
		virtual void		execute(Bureaucrat const & executor) const = 0;
		class	GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class	GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
		class	FormNotSignedException : public std::exception {
			public:
				const char* what() const throw();
		};
	private:
		const std::string	name;
		const int			grade_required_to_sign;
		const int			grade_required_to_execute;
		bool				is_signed;
};

std::ostream	&operator<<(std::ostream &o, const AForm &form);

#endif
