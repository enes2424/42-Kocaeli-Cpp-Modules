#ifndef ITER
#define ITER

#include <iostream>

template <typename T>
void	iter(T *arr, int len, void (*f)(T &)) {
	int	i;
	for (i = 0; i < len; i++)
		f(arr[i]);
}

template <typename T>
void	add_with_self(T &elm) {
	elm += elm;
}

#endif
