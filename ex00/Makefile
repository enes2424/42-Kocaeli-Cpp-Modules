SRCS	=  megaphone.cpp

C++ = c++
RM = rm -f
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = megaphone

all : $(NAME)

$(NAME) :
		$(C++) $(FLAGS) $(SRCS) -o $(NAME)

clean :
	$(RM) $(NAME)

re : clean $(NAME)

.PHONY : all clean  re
