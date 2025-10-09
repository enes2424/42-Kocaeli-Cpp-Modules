#include "Array.hpp"

int main( void ) {
	Array<int>	arr(20);
	size_t		i;

	std::cout << "size : " << arr.size() << std::endl << std::endl;
	for (i = 0; i < arr.size(); i++)
		arr[i] = (i + 1) * (i + 1);

	for (i = 0; i < arr.size() - 1; i++)
		std::cout << arr[i] << ", ";
	std::cout << arr[i] << std::endl << std::endl;

	try {
		arr[25] = -1;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	try {
		arr[-5] = 354;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	Array<int> arr2;

	arr2 = arr;
	for (i = 0; i < arr2.size() - 1; i++)
		std::cout << arr2[i] << ", ";
	std::cout << arr2[i] << std::endl << std::endl;

	Array<std::string> arr3(3);

	arr3[0] = "42Kocaeli";
	arr3[1] = "Enes";
	arr3[2] = "Turkiye";

	std::cout << "size : " << arr3.size() << std::endl << std::endl;

	for (i = 0; i < arr3.size(); i++)
		std::cout << arr3[i] << std::endl;
	return 0;
}
