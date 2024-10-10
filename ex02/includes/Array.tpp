#include "Array.hpp"

template <class T>
Array<T>::Array() : array(NULL), n(0)
{
}

//! Parameterized constructor
template <class T>
Array<T>::Array(unsigned int n) : n(n)
{
	this->array = new T[this->n];
	for (unsigned int i = 0; i < this->n; i++)
		this->array[i] = T();
}

//! Copy constructor
template <class T>
Array<T>::Array(const Array& copy)
{
	this->array = NULL;
	*this = copy;
}

//! Destructor
template <class T>
Array<T>::~Array()
{
	delete [] array;
}

//! Return the size of the array
template <class T>
unsigned int Array<T>::size(void) const
{
	return (this->n);
}

//! Assignment operator overload
template <class T>
Array<T>& Array<T>::operator =(const Array<T>& right)
{
	if (this == &right)
		return (*this);

	delete [] this->array;

	this->n = right.n;
	this->array = new T[this->n];
	for (unsigned int i = 0; i < this->n; i++)
		this->array[i] = right.array[i];

	return (*this);
}

//! Operator [] overload
template <class T>
T& Array<T>::operator [](unsigned int index)
{
	if (index >= this->n)
		throw Array<T>::IndexOutOfBoundsException();
	return (this->array[index]);
}

//! Exception handling for out-of-bounds access
template <class T>
const char* Array<T>::IndexOutOfBoundsException::what() const throw()
{
	return ("Array Exception: index out of bounds");
}
