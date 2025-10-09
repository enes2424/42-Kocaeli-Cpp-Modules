#ifndef PMERGEME
#define PMERGEME
#include <iostream>
#include <deque>
#include <vector>
#include <iomanip>
#include <ctime>
#include <algorithm>
#include <cstring>

using std::cout;
using std::endl;
using std::string;
using std::clock_t;
using std::clock;
using std::exception;
using std::runtime_error;
using std::pair;
using std::strlen;

class PmergeMe {
	private:
		PmergeMe(void);
		PmergeMe(const PmergeMe &other);
		PmergeMe	&operator=(const PmergeMe &other);
		~PmergeMe(void);
	public:
		static void	exec(int argc, char **argv);
};

#endif
