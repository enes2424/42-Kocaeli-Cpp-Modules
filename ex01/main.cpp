#include "iter.hpp"

int main( void ) {
	int i;

	int	arr[] = {1, 2, 3, 4, 5};
	for (i = 0; i < 4; i++)
		std::cout << arr[i] << ", ";
	std::cout << arr[i] << std::endl;
	iter(arr, 5, &add_with_self);
	for (i = 0; i < 4; i++)
		std::cout << arr[i] << ", ";
	std::cout << arr[i] << std::endl << std::endl;

	std::string	arr2[] = {"42", "Kocaeli", "Enes", "Eboş", "Azra"};
	for (i = 0; i < 4; i++)
		std::cout << arr2[i] << ", ";
	std::cout << arr2[i] << std::endl;
	iter(arr2, 5, &add_with_self);
	for (i = 0; i < 4; i++)
		std::cout << arr2[i] << ", ";
	std::cout << arr2[i] << std::endl << std::endl;

	double	arr3[] = {34.32, 65.76, 980.21, 324.676, 21.333};
	for (i = 0; i < 4; i++)
		std::cout << arr3[i] << ", ";
	std::cout << arr3[i] << std::endl;
	iter(arr3, 5, &add_with_self);
	for (i = 0; i < 4; i++)
		std::cout << arr3[i] << ", ";
	std::cout << arr3[i] << std::endl;

	return 0;
}
