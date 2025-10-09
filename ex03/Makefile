SRCS	=  main.cpp Fixed.cpp Point.cpp bsp.cpp

C++ = c++
RM = rm -f
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = a.out

all : $(NAME)

$(NAME) : Fixed.hpp Point.hpp $(SRCS)
	$(C++) $(FLAGS) $(SRCS) -o $(NAME)

clean :
	$(RM) $(NAME)

re : clean $(NAME)

.PHONY : all clean  re
