C++ = c++
RM = rm -f
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = AtLeastThisBeatsCoffeeMaking

SRCS	= main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp

BSRCS	= $(SRCS:.cpp=.o)

.cpp.o:
	$(C++) $(FLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp Intern.hpp $(BSRCS)
		@$(C++) $(FLAGS) $(BSRCS) -o $(NAME)

clean :
	@$(RM) $(BSRCS)

fclean : clean
	@$(RM) $(NAME)
	@$(RM) *_shrubbery

re : fclean
	make

.PHONY : all clean fclean re
