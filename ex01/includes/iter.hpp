#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <sstream>

template <class T>
void iter(T *array, int len, void (*f)(T&))
{
	for (int i = 0; i < len; i++)
		(*f)(array[i]);
}

template <class T>
void print(T& val)
{
	std::cout << val << std::endl;
}

#endif
