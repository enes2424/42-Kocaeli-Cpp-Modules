#ifndef ARRAY
#define ARRAY

#include <iostream>

template <typename T>
class Array {
	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array &other);
		Array	&operator=(const Array &other);
		~Array(void);
		T	&operator[](unsigned int n);
		unsigned int	size(void);
		class	OutOfBounds : public std::exception {
			public:
				const char*	what() const throw();
		};
	private:
		T				*arr;
		unsigned int	len;
};

template <typename T>
Array<T>::Array(void) {
	arr = NULL;
	len = 0;
}

template <typename T>
Array<T>::Array(unsigned int n) {
	arr = new T[n];
	len = n;
}

template <typename T>
Array<T>::Array(const Array<T> &other) {
	arr = NULL;
	*this = other;
}

template <typename T>
Array<T>	&Array<T>::operator=(const Array<T> &other) {
	if (this != &other) {
		delete[] arr;
		len = other.len;
		arr = new T[len];
		size_t i;
		for (i = 0; i < len; i++)
			arr[i] = other.arr[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array(void) {
	delete[] arr;
}

template <typename T>
T	&Array<T>::operator[](unsigned int n) {
	if (n < 0 || n >= len)
		throw OutOfBounds();
	return arr[n];
}

template <typename T>
const char*	Array<T>::OutOfBounds::what() const throw() {
	return "index is out of bounds";
}

template <typename T>
unsigned int	Array<T>::size(void) {
	return len;
}

#endif
