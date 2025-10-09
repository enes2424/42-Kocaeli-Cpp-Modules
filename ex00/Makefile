SRCS	= main.cpp Animal.cpp WrongAnimal.cpp Dog.cpp Cat.cpp WrongCat.cpp

C++ = c++
RM = rm -f
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = Polymorphism

all : $(NAME)

$(NAME) : Animal.hpp Dog.hpp Cat.hpp WrongAnimal.hpp WrongCat.hpp $(SRCS)
	$(C++) $(FLAGS) $(SRCS) -o $(NAME)

clean :
	$(RM) $(NAME)

re : clean $(NAME)

.PHONY : all clean re
