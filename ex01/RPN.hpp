#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

using std::cout;
using std::endl;
using std::string;
using std::runtime_error;
using std::exception;

class Rpn {
		Rpn(void);
		Rpn(const Rpn &other);
		Rpn	&operator=(const Rpn &other);
		~Rpn(void);
	public:
		static void	exec(string str);
};

#endif
