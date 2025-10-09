SRCS	= main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp

C++ = c++
RM = rm -f
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = AtLeastThisBeatsCoffeeMaking

OBJS	= $(SRCS:.cpp=.o)

.cpp.o:
	$(C++) $(FLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp Intern.hpp $(OBJS)
		@$(C++) $(FLAGS) $(OBJS) -o $(NAME)

clean :
	@$(RM) $(OBJS)

fclean : clean
	@$(RM) $(NAME)
	@$(RM) *_shrubbery

re : fclean all

.PHONY : all clean fclean re
