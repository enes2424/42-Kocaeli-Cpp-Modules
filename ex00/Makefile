SRCS	= main.cpp

C++ = c++
RM = rm -f
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = ex00

OBJS	= $(SRCS:.cpp=.o)

.cpp.o:
	$(C++) $(FLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : easyfind.hpp $(OBJS)
		$(C++) $(FLAGS) $(OBJS) -o $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re