#ifndef EASYFIND
#define EASYFIND

#include <iostream>

class NotFoundException : public std::exception
{
	public:
		virtual const char *what() const throw() {
			return ("Not found");
		}
};

template <typename T>
typename T::iterator easyfind(T &t, int num) {
	typename T::iterator	iter;
	for (iter = t.begin(); iter != t.end(); iter++)
		if (*iter == num)
			return iter;
	throw	NotFoundException();
}

#endif
