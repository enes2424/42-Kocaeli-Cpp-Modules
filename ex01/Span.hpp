#ifndef SPAN
#define SPAN

#include <iostream>
#include <vector>

class MaximumExceedance : public std::exception
{
	public:
		virtual const char *what() const throw() {
			return ("you have exceeded the maximum storage");
		}
};

class Impossible : public std::exception
{
	public:
		virtual const char *what() const throw() {
			return ("there is no element or only one element");
		}
};

class Span {
	public:
		Span(void);
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span(void);
		void	addNumber(int num);
		void	improveAddNumber(int len, int *nums);
		int		shortestSpan(void);
		int		longestSpan(void);
	private:
		std::vector<int>	lst;
		unsigned int		max_len;
};

#endif
