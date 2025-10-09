#include "Span.hpp"
#include <algorithm>

Span::Span(void) {
	max_len = 0;
}

Span::Span(unsigned int N) {
	max_len = N;
}

Span::Span(const Span &other) {
	*this = other;
}

Span &Span::operator=(const Span &other) {
	lst = other.lst;
	max_len = other.max_len;
	return *this;
}

Span::~Span(void) {
}

void	Span::addNumber(int num) {
	if (lst.size() == max_len)
		throw MaximumExceedance();
	lst.push_back(num);
}

void	Span::improveAddNumber(int len, int *nums) {
	if (lst.size() + len > max_len)
		throw MaximumExceedance();
	lst.insert(lst.end(), nums, nums + len - 1);
	lst.push_back(nums[len - 1]);
}

int		Span::shortestSpan(void) {
	if (lst.size() <= 1)
		throw Impossible();
	std::sort(lst.begin(), lst.end());
	int short_val = lst[1] - lst[0];
	if (!short_val)
		return short_val;
	unsigned int i, len = lst.size();
	for (i = 1; i < len - 1; i++)
		if (lst[i + 1] - lst[i] < short_val && !(short_val = lst[i + 1] - lst[i]))
			return short_val;
	return short_val;
}

int		Span::longestSpan(void) {
	if (lst.size() <= 1)
		throw Impossible();
	std::sort(lst.begin(), lst.end());
	return lst[lst.size() - 1] - lst[0];
}
