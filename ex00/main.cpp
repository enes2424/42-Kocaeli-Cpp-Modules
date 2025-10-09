#include "easyfind.hpp"
#include <vector>
#include <list>

int main( void ) {
	int	arr[] = {3, 2, 5, 6, 8, 1};
	std::vector<int> vector;
	vector.insert(vector.begin(), &arr[0], &arr[5]);
	vector.push_back(arr[5]);
	std::vector<int>::iterator iter = easyfind(vector, 5);
	for (; iter != vector.end(); iter++)
		std::cout << *iter << std::endl;
	try {
		iter = easyfind(vector, -5);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	int	arr2[] = {0, 24, 12, -57, 7, 9, -1, -5};
	std::list<int> list;
	list.insert(list.begin(), &arr2[0], &arr2[7]);
	list.push_back(arr2[7]);
	std::list<int>::iterator iter2 = easyfind(list, -57);
	for (; iter2 != list.end(); iter2++)
		std::cout << *iter2 << std::endl;
	return 0;
}
