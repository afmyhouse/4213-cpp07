#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <class T>
void iter(T *array, const size_t len, void (*f)(const T&))
{
	for (size_t i = 0; i < len; i++)
		(*f)(array[i]);
}

template <class T>
void print(const T& val)
{
	std::cout << val << std::endl;
}

#endif
