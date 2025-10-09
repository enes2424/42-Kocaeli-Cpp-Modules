SRCS	= main.cpp Span.cpp

C++ = c++
RM = rm -f
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = ex01

OBJS	= $(SRCS:.cpp=.o)

.cpp.o:
	$(C++) $(FLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : Span.hpp $(OBJS)
		$(C++) $(FLAGS) $(OBJS) -o $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re