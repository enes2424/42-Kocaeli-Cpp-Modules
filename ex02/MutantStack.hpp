#ifndef MUTANTSTACK
#define MUTANTSTACK
#include <iostream>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack(void) {}
		MutantStack(MutantStack &other) {*this = other;}
		MutantStack	&operator=(MutantStack &other) {
			if (this == &other)
				return *this;
			while (this->size())
				this->pop();
			class iterator it = other.begin();
			class iterator ite = other.end();
			while (it != ite) {
				this->push(*it);
				++it;
			}
			return *this;
		}
		~MutantStack(void) {}
		class iterator {
			private:
				T	*value;
			public:
				iterator(T *value) {this->value = value;}
				T& operator*() {
					return *value;
				}
				iterator& operator++() {
					value++;
					return *this;
				}
				iterator  operator++(int) {
					iterator	tmp = *this;
					value++;
					return tmp;
				}
				iterator& operator--() {
					value--;
					return *this;
				}
				iterator  operator--(int) {
					iterator	tmp = *this;
					value--;
					return tmp;
				}
				bool operator==(const iterator& other) const {
					return value == other.value;
				}
				bool operator!=(const iterator& other) const {
					return value != other.value;
				}
		};

		iterator	begin(void) {
			if (this->size() == 0)
				return NULL;
			std::stack<T>	tmp;
			while (this->size() > 1) {
				tmp.push(this->top());
				this->pop();
			}
			T *value = &this->top();
			while (tmp.size()) {
				this->push(tmp.top());
				tmp.pop();
			}
			return value;
		}

		iterator	end(void) {
			if (this->size() == 0)
				return NULL;
			return (&this->top()) + 1;
		}
};

#endif
