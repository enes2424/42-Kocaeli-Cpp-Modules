SRCS	= PmergeMe.cpp main.cpp

C++ = c++
RM = rm -f
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = PmergeMe

OBJS	= $(SRCS:.cpp=.o)

.cpp.o:
	$(C++) $(FLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : PmergeMe.hpp $(OBJS)
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
