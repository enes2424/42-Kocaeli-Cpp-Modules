#include "Point.hpp"

int main(void)
{
	Point a(1, 1);
	Point b(2, 5);
	Point c(5, 4);
	Point p(2, 3);

	std::cout << bsp(a, b, c, p) << std::endl;
	return 0;
}
