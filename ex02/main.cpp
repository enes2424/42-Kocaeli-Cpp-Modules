#include "PmergeMe.hpp"

int	main(int argc, char **argv) {
	try {
		PmergeMe::exec(argc - 1, argv + 1);
	} catch(exception &e) {
		cout << e.what() << endl;
	}
	return 0;
}
