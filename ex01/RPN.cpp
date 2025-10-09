#include "RPN.hpp"

Rpn::Rpn(void) {}
Rpn::Rpn(const Rpn &other) {*this = other;}
Rpn	&Rpn::operator=(const Rpn &other) {return (void)other, *this;}
Rpn::~Rpn(void) {}

void	Rpn::exec(string str) {
	std::stack<int>	stack;
	int			i = 0, len = str.length(), tmp;
	for (; i < len; i++) {
		if (str[i] != ' ') {
			if (i + 1 != len && str[i + 1] != ' ')
				throw runtime_error("Error");
			if (str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '-') {
				if (stack.size() < 2)
					throw runtime_error("Error");
				tmp = stack.top();
				stack.pop();
				switch (str[i]) {
					case '*':
						tmp = stack.top() * tmp;
						break;
					case '/':
						if (tmp == 0)
							throw runtime_error("Division by zero!!");
						tmp = stack.top() / tmp;
						break;
					case '+':
						tmp = stack.top() + tmp;
						break;
					case '-':
						tmp = stack.top() - tmp;
						break;
				}
				stack.pop();
				stack.push(tmp);
			}
			else if (str[i] >= '0' && str[i] <= '9')
				stack.push(str[i] - 48);
			else
				throw runtime_error("Error");
		}
	}
	if (stack.size() != 1)
		throw runtime_error("Error");
	cout << stack.top() << endl;
}
