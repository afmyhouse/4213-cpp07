/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:46:31 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/09/22 21:18:21 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <sstream>

# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define RESET	"\033[0m"

# define ERROR(x) 		std::cout << x << std::endl
# define ERROR_USAGE(e)	ERROR("Usage: " << e << " test_number")
# define ERROR_NOT_INT	ERROR("Error: test number must be a number")
# define ERROR_TESTNO	ERROR("Error: test number must be bounded between 0 and 1")

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

	class IndexOutOfBoundsException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
		
};

#include "Array.tpp"

#endif
