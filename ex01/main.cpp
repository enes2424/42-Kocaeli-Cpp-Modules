#include "Span.hpp"

int main( void ) {
	Span sp = Span(5);

	try {
		std::cout << sp.shortestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	sp.addNumber(6);

	try {
		std::cout << sp.shortestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	int	arr[] = {3, 17, 9, 11};
	sp.improveAddNumber(4, arr);

	try {
		sp.addNumber(-11);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	Span sp2 = Span(10000);
	int	num = 0, sign = 1;
	try {
		while (true) {
			num++;
			sp2.addNumber(num * num * sign);
			sign *= -1;
		}
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;

	return 0;
}
