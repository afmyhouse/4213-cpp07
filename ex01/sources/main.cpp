/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:03:13 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/09/23 11:24:42 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

/* ________________________ TESTS ________________________ */

void testIntegerArray(void)
{
	std::cout << GREEN << "\n\t =============== TEST INTEGERS ===============\n\n" << RESET;
	
	int array[] = {1, 2, 3, 4, 5, 42, -1, 0};
	iter(array, sizeof(array)/sizeof(int), &print);	
}

void testStringArray(void)
{
	std::cout << GREEN << "\n\t =============== TEST STRINGS ===============\n\n" << RESET;
	
	std::string array[] = 
	{
		"Nuno",
		"Miguel",
		"Carvalho",
		"Jesus",
	};
	iter(array, sizeof(array)/sizeof(std::string), &print);	
}

void testAlphabet(void)
{	
	std::cout << GREEN << "\n\t =============== TEST ALPHABET ===============\n\n" << RESET;
	
	char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	iter(alphabet, sizeof(alphabet), &print);
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
		testIntegerArray();
	else if (testno == 1)
		testStringArray();
	else
		testAlphabet();
	return (0);
}
