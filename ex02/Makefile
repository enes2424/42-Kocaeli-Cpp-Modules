C++ = c++
RM = rm -f
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = NoYouNeedForm28BNot28C

SRCS	= main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp

BSRCS	= $(SRCS:.cpp=.o)

.cpp.o:
	$(C++) $(FLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp $(BSRCS)
		@$(C++) $(FLAGS) $(BSRCS) -o $(NAME)

clean :
	@$(RM) $(BSRCS)

fclean : clean
	@$(RM) $(NAME)
	@$(RM) *_shrubbery

re : fclean
	make

.PHONY : all clean fclean re
