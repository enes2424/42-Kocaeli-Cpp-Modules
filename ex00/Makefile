SRCS	=  main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

C++ = c++
RM = rm -f
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = BraiiiiiiinnnzzzZ

all : $(NAME)

$(NAME) : Zombie.hpp $(SRCS)
		$(C++) $(FLAGS) $(SRCS) -o $(NAME)

clean :
	$(RM) $(NAME)

re : clean $(NAME)

.PHONY : all clean  re
