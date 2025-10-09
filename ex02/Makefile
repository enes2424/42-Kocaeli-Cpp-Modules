SRCS	=  Account.cpp tests.cpp

C++ = c++
RM = rm -f
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = Account

all : $(NAME)

$(NAME) : Account.hpp $(SRCS)
		$(C++) $(FLAGS) $(SRCS) -o $(NAME)

clean :
	$(RM) $(NAME)

re : clean $(NAME)

.PHONY : all clean  re
