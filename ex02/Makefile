SRCS	= main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

C++ = c++
RM = rm -f
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = RepetitiveWork

all : $(NAME)

$(NAME) : ClapTrap.hpp ScavTrap.hpp FragTrap.hpp $(SRCS)
		$(C++) $(FLAGS) $(SRCS) -o $(NAME)

clean :
	$(RM) $(NAME)

re : clean $(NAME)

.PHONY : all clean re