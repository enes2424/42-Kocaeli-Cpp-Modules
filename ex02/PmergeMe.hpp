#ifndef PMERGEME
#define PMERGEME
#include <iostream>
#include <deque>
#include <vector>
#include <iomanip>
#include <ctime>
#include <algorithm>
#include <cstring>

using std::clock;
using std::clock_t;
using std::cout;
using std::deque;
using std::endl;
using std::exception;
using std::pair;
using std::runtime_error;
using std::string;
using std::strlen;
using std::vector;

class PmergeMe
{
	PmergeMe(void);
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe(void);

public:
	static void exec(int argc, char **argv);
};

#endif