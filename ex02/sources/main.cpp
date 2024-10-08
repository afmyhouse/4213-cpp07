/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 21:10:10 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/09/22 21:21:37 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

void testDefaultConstructor(void)
{
	std::cout << GREEN << "\n\t ======= Testing Array Default Constructor =======\n\n" << RESET;
	
	Array<int> numbers(10);

	for (size_t i = 0; i < numbers.size(); i++)
		std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
}

void testCopyConstructor(void)
{
	std::cout << GREEN << "\n\t ======= Testing Array Copy Constructor =======\n\n" << RESET;
	
	Array<int> numbers(10);
	Array<int> copy(5);

	for (size_t i = 0; i < numbers.size(); i++)
		numbers[i] = 42;

	copy = numbers;
	numbers[0] = 21;
	for (size_t i = 0; i < copy.size(); i++)
		std::cout << "copy[" << i << "] = " << copy[i] << std::endl;
}

void testOutOfBoundsIndexes(void)
{
	std::cout << GREEN << "\n\t ======= Testing Array Invalid Index =======\n\n" << RESET;
	Array<int> numbers(10);
	
	try
	{
		numbers[-1] = 0;
	}
	catch (const std::exception &e)
	{
		std::cout << RED << e.what() << RESET << '\n';
	}
	
	try
	{
		numbers[10] = 0;
	}
	catch (const std::exception &e)
	{
		std::cout << RED << e.what() << RESET << '\n';
	}
}

int main(int argc, char **argv)
{
	int					testno;
	std::stringstream	stream;

	if (argc < 2)
		return (ERROR_USAGE(argv[0]), 1);
	stream << argv[1];
	if (!(stream >> testno))
		return (ERROR_NOT_INT, 1);
	if (testno < 0 || testno > 2)
		return (ERROR_TESTNO, 1);
	if (testno == 0)
		testDefaultConstructor();
	else if (testno == 1)
		testCopyConstructor();
	else
		testOutOfBoundsIndexes();
	return 0;
}
