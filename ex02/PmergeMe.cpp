#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}
PmergeMe::PmergeMe(const PmergeMe &other) {*this = other;}
PmergeMe	&PmergeMe::operator=(const PmergeMe &other) {return (void)other, *this;}
PmergeMe::~PmergeMe(void) {}

static int	special_atoi(char *str) {
	long	num = 0, i = (str[0] == '+');

	if (str[0] == '\0' || strlen(str) > 10)
		throw runtime_error("Error");

	for (; str[i]; i++) {
		if (str[i] < '0' || str[i] > '9')
			throw runtime_error("Error");
		num = 10 * num + str[i] - 48;
	}
	if (num > 2147483647)
		throw runtime_error("Error");
	return num;
}

static std::vector<int> generate_jacobsthal_sequence(int n) {
	std::vector<int> jacobsthal;
	if (n <= 0) return jacobsthal;
	
	jacobsthal.push_back(0);
	if (n == 1) return jacobsthal;
	
	jacobsthal.push_back(1);
	
	int a = 0, b = 1;
	while (true) {
		int next = b + 2 * a;
		if (next >= n) break;
		jacobsthal.push_back(next);
		a = b;
		b = next;
	}
	return jacobsthal;
}

template<typename T>
static typename T::iterator binary_search_position(typename T::iterator begin, 
													typename T::iterator end, int value) {
	while (begin != end) {
		typename T::iterator mid = begin;
		std::advance(mid, std::distance(begin, end) / 2);
		
		if (*mid < value) {
			begin = mid;
			++begin;
		} else {
			end = mid;
		}
	}
	return begin;
}

template<typename T>
static void ford_johnson_sort(T& container) {
	if (container.size() <= 1) return;
	
	std::vector<pair<int, int> > pairs;
	bool has_odd = container.size() % 2 == 1;
	int odd_element = has_odd ? container.back() : 0;
	
	for (size_t i = 0; i < container.size() - (has_odd ? 1 : 0); i += 2) {
		int first = container[i];
		int second = container[i + 1];
		if (first > second) {
			pairs.push_back(std::make_pair(second, first));
		} else {
			pairs.push_back(std::make_pair(first, second));
		}
	}
	
	if (pairs.empty()) {
		if (has_odd) {
			container.clear();
			container.push_back(odd_element);
		}
		return;
	}
	
	T larger_elements;
	std::vector<int> smaller_elements;
	
	for (size_t i = 0; i < pairs.size(); ++i) {
		const pair<int, int>& p = pairs[i];
		larger_elements.push_back(p.second);
		smaller_elements.push_back(p.first);
	}
	
	ford_johnson_sort(larger_elements);
	
	T main_chain = larger_elements;
	
	if (!smaller_elements.empty()) {
		main_chain.insert(main_chain.begin(), smaller_elements[0]);
	}
	
	std::vector<int> jacobsthal = generate_jacobsthal_sequence(smaller_elements.size());
	std::vector<bool> inserted(smaller_elements.size(), false);
	if (!smaller_elements.empty()) inserted[0] = true;
	
	for (size_t j = 1; j < jacobsthal.size(); ++j) {
		int limit = jacobsthal[j];
		
		for (int k = std::min(limit, (int)smaller_elements.size() - 1); k >= 1; --k) {
			if (!inserted[k]) {
				typename T::iterator pos = binary_search_position<T>(
					main_chain.begin(), main_chain.end(), smaller_elements[k]);
				main_chain.insert(pos, smaller_elements[k]);
				inserted[k] = true;
			}
		}
	}
	
	for (size_t i = 1; i < smaller_elements.size(); ++i) {
		if (!inserted[i]) {
			typename T::iterator pos = binary_search_position<T>(
				main_chain.begin(), main_chain.end(), smaller_elements[i]);
			main_chain.insert(pos, smaller_elements[i]);
		}
	}
	
	if (has_odd) {
		typename T::iterator pos = binary_search_position<T>(
			main_chain.begin(), main_chain.end(), odd_element);
		main_chain.insert(pos, odd_element);
	}
	
	container = main_chain;
}

void	PmergeMe::exec(int argc, char **argv) {
	if (argc == 0)
		throw runtime_error("Error");

	int		*arr = new int[argc], i = 0;
	clock_t	start, end;

	for (; i < argc; i++) {
		try {
			arr[i] = special_atoi(argv[i]);
		} catch (exception &e) {
			delete[] arr;
			throw runtime_error(e.what());
		}
	}
	
	cout << "Before:\t";
	for (i = 0; i < argc; i++)
		cout << arr[i] << " ";
	cout << endl;

	start = clock();
	{
		std::vector<int>	vector;
		for (i = 0; i < argc; i++)
			vector.push_back(arr[i]);
		ford_johnson_sort(vector);
		
		for (i = 0; i < argc; i++)
			arr[i] = vector[i];
	}
	end = clock();
	double vector_elapsed_seconds = double(end - start) / CLOCKS_PER_SEC;
	
	start = clock();
	{
		std::deque<int>	deque;
		for (i = 0; i < argc; i++)
			deque.push_back(arr[i]);
		ford_johnson_sort(deque);
	}
	end = clock();
	double deque_elapsed_seconds = double(end - start) / CLOCKS_PER_SEC;
	
	cout << "After:\t";
	for (i = 0; i < argc; i++)
		cout << arr[i] << " ";
	cout << endl << std::fixed << std::setprecision(5);
	
	delete[] arr;
	cout << "Time to process a range of " << argc << " elements with std::vector : " << vector_elapsed_seconds << " us" << endl;
	cout << "Time to process a range of " << argc << " elements with std::deque : " << deque_elapsed_seconds << " us" << endl;
}
