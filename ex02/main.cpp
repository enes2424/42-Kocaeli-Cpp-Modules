#include "MutantStack.hpp"

int main() {
	MutantStack<int> mstack;

	mstack.push(6);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int> mstack2 = mstack;
	MutantStack<int>::iterator it = mstack2.begin();
	MutantStack<int>::iterator ite = mstack2.end();

	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack2);
	return 0;
}
