SRCS	= main.cpp RPN.cpp

C++ = c++
RM = rm -f
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = RPN

OBJS	= $(SRCS:.cpp=.o)

.cpp.o:
	$(C++) $(FLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : RPN.hpp $(OBJS)
		$(C++) $(FLAGS) $(OBJS) -o $(NAME)

c : clean
clean :
	$(RM) $(OBJS)

f : fclean
fclean : clean
	$(RM) $(NAME)

r: re
re : fclean all

.PHONY : all clean fclean re
