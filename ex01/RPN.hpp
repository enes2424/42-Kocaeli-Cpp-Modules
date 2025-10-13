#ifndef RPN
#define RPN

#include <iostream>
#include <stack>

using std::cout;
using std::endl;
using std::exception;
using std::runtime_error;
using std::string;

class Rpn
{
	Rpn(void);
	Rpn(const Rpn &other);
	Rpn &operator=(const Rpn &other);
	~Rpn(void);

public:
	static void exec(string str);
};

#endif
