SRCS	=  AMateria.cpp main.cpp MateriaSource.cpp Character.cpp Ice.cpp Cure.cpp

C++ = clang++
RM = rm -f
FLAGS = -Wextra -Wall -Werror -std=c++98
NAME = InterfaceAndrace

all : $(NAME)

$(NAME) : AMateria.hpp Character.hpp Cure.hpp Ice.hpp MateriaSource.hpp $(SRCS)
	$(C++) $(FLAGS) $(SRCS) -o $(NAME)

clean :
	$(RM) $(NAME)

re : clean $(NAME)

.PHONY : all clean re