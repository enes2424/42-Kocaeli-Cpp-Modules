SRCS	= main.cpp ClapTrap.cpp ScavTrap.cpp

C++ = c++
RM = rm -f
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = SerenaMyLove

all : $(NAME)

$(NAME) : ClapTrap.hpp ScavTrap.hpp $(SRCS)
		$(C++) $(FLAGS) $(SRCS) -o $(NAME)

clean :
	$(RM) $(NAME)

re : clean $(NAME)

.PHONY : all clean re
