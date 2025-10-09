SRCS	=  main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

C++ = c++
RM = rm -f
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = GereksizSiddet

all : $(NAME)

$(NAME) : Weapon.hpp HumanA.hpp HumanB.hpp $(SRCS)
		$(C++) $(FLAGS) $(SRCS) -o $(NAME)

clean :
	$(RM) $(NAME)

re : clean $(NAME)

.PHONY : all clean  re
