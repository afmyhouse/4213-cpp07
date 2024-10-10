#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <sstream>

template <class T>
class Array
{
	private:
		T *array;
		unsigned int n;

	public:
		//! Constructors and destructor
		Array();
		Array(unsigned int n);
		Array(const Array& copy);
		~Array();

		//! Member functions
		unsigned int size(void) const;

		//! Operator overloading
		Array& operator=(const Array& right);
		T& operator[](unsigned int index);

	//! Exception handling for out-of-bounds access
	class IndexOutOfBoundsException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

# include "Array.tpp"

#endif
