#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}
PmergeMe::PmergeMe(const PmergeMe &other) { *this = other; }
PmergeMe &PmergeMe::operator=(const PmergeMe &other) { return (void)other, *this; }
PmergeMe::~PmergeMe(void) {}

static int special_atoi(char *str)
{
	long num = 0, i = (str[0] == '+');

	if (str[0] == '\0' || strlen(str) > 10)
		throw runtime_error("Error");

	for (; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			throw runtime_error("Error");

		num = 10 * num + str[i] - 48;

		if (num > 2147483647)
			throw runtime_error("Error");
	}

	return num;
}

static std::vector<int> generate_jacobsthal_sequence(int n)
{
	std::vector<int> jacobsthal;

	if (n <= 0)
		return jacobsthal;

	jacobsthal.push_back(0);

	if (n == 1)
		return jacobsthal;

	jacobsthal.push_back(1);

	int a = 0, b = 1;

	while (true)
	{
		int next = b + 2 * a;

		if (next >= n)
			break;

		jacobsthal.push_back(next);
		a = b;
		b = next;
	}

	return jacobsthal;
}

template <typename T>
static typename T::iterator binary_search_position(typename T::iterator begin,
												   typename T::iterator end, int value)
{
	typename T::iterator mid;

	while (begin != end)
	{
		mid = begin;
		std::advance(mid, std::distance(begin, end) / 2);

		if (*mid < value)
			begin = mid + 1;
		else
			end = mid;
	}

	return begin;
}

template <typename T>
static void ford_johnson_sort(T &container)
{
	if (container.size() <= 1)
		return;

	typedef std::pair<int, int> stdpair;

	std::vector<stdpair> pairs;
	bool has_odd = container.size() % 2 == 1;
	int odd_element = has_odd ? container.back() : 0;

	for (size_t i = 0; i + 2 <= container.size(); i += 2)
	{
		int first = container[i];
		int second = container[i + 1];
		if (first > second)
			pairs.push_back(std::make_pair(second, first));
		else
			pairs.push_back(std::make_pair(first, second));
	}

	T larger_elements;
	for (size_t i = 0; i < pairs.size(); ++i)
		larger_elements.push_back(pairs[i].second);

	ford_johnson_sort(larger_elements);

	T main_chain = larger_elements;

	std::vector<int> jacobsthal = generate_jacobsthal_sequence(pairs.size());
	std::vector<bool> inserted(pairs.size(), false);

	for (size_t i = 0; i < pairs.size(); ++i)
	{
		if (pairs[i].second == larger_elements[0])
		{
			main_chain.insert(main_chain.begin(), pairs[i].first);
			inserted[i] = true;
			break;
		}
	}

	for (size_t j = 1; j < jacobsthal.size(); ++j)
	{
		for (int k = jacobsthal[j]; k > jacobsthal[j - 1]; --k)
		{
			if (!inserted[k])
			{
				for (size_t p = 0; p < pairs.size(); ++p)
				{
					if (!inserted[p] && pairs[p].second == larger_elements[k])
					{
						typename T::iterator pos = binary_search_position<T>(
							main_chain.begin(), main_chain.end(), pairs[p].first);
						main_chain.insert(pos, pairs[p].first);
						inserted[p] = true;
						break;
					}
				}
			}
		}
	}

	for (size_t i = 0; i < pairs.size(); ++i)
	{
		if (!inserted[i])
		{
			typename T::iterator pos = binary_search_position<T>(
				main_chain.begin(), main_chain.end(), pairs[i].first);
			main_chain.insert(pos, pairs[i].first);
		}
	}

	if (has_odd)
	{
		typename T::iterator pos = binary_search_position<T>(
			main_chain.begin(), main_chain.end(), odd_element);
		main_chain.insert(pos, odd_element);
	}

	container = main_chain;
}

void PmergeMe::exec(int argc, char **argv)
{
	if (argc == 0)
		throw runtime_error("Error");

	int *arr = new int[argc], i = 0, j, tmp;
	clock_t start, end;

	for (; i < argc; i++)
	{
		try
		{
			arr[i] = special_atoi(argv[i]);
		}
		catch (exception &e)
		{
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
		std::vector<int> vector;
		for (i = 0; i < argc; i++)
			vector.push_back(arr[i]);
		ford_johnson_sort(vector);
	}
	end = clock();
	double vector_elapsed_seconds = double(end - start) / CLOCKS_PER_SEC;

	start = clock();
	{
		std::deque<int> deque;
		for (i = 0; i < argc; i++)
			deque.push_back(arr[i]);
		ford_johnson_sort(deque);
	}
	end = clock();
	double deque_elapsed_seconds = double(end - start) / CLOCKS_PER_SEC;

	cout << "After:\t";
	for (i = 0; i < argc - 1; i++)
	{
		for (j = i + 1; j < argc; j++)
			if (arr[j] < arr[i])
			{
				tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
			}
		cout << arr[i] << " ";
	}
	cout << arr[i] << endl
		 << std::fixed << std::setprecision(5);

	delete[] arr;
	cout << "Time to process a range of " << argc << " elements with std::vector : " << vector_elapsed_seconds << " us" << endl;
	cout << "Time to process a range of " << argc << " elements with std::deque : " << deque_elapsed_seconds << " us" << endl;
}
