SRCS	= main.cpp ClapTrap.cpp

C++ = c++
RM = rm -f
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = AaaaandOPEN

all : $(NAME)

$(NAME) : ClapTrap.hpp $(SRCS)
		$(C++) $(FLAGS) $(SRCS) -o $(NAME)

clean :
	$(RM) $(NAME)

re : clean $(NAME)

.PHONY : all clean re
