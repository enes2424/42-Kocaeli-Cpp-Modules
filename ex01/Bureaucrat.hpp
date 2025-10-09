#ifndef BUREAUCRAT
#define BUREAUCRAT
#include <iostream>

class Bureaucrat {
	public:
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat	&operator=(const Bureaucrat &other);
		~Bureaucrat(void);
		const std::string	&getName(void) const;
		int					getGrade(void) const;
		void				increment(void);
		void				decrement(void);
		void				signForm(class Form &form);
		class	GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class	GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
	private:
		const	std::string name;
		int		grade;
};

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &bureaucrat);

#endif
