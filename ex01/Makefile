SRCS	=  phonebook.cpp contact.cpp my_awesome_phonebook.cpp

C++ = c++
RM = rm -f
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = my_awesome_phonebook

all : $(NAME)

$(NAME) : my_awesome_phonebook.hpp $(SRCS)
		$(C++) $(FLAGS) $(SRCS) -o $(NAME)

clean :
	$(RM) $(NAME)

re : clean $(NAME)

.PHONY : all clean  re
