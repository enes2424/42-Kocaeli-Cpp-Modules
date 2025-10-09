C++ = c++
RM = rm -f
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = ex02

SRCS	= main.cpp

BSRCS	= $(SRCS:.cpp=.o)

.cpp.o:
	$(C++) $(FLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : MutantStack.hpp $(BSRCS)
		$(C++) $(FLAGS) $(BSRCS) -o $(NAME)

clean :
	$(RM) $(BSRCS)

fclean : clean
	$(RM) $(NAME)

re : fclean
	make

.PHONY : all clean fclean re