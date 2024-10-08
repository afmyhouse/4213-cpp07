#include "iter.hpp"
#include "../includes/tests.hpp"

void testIntegers(int test)
{
	SHOW(SBLUE << test << " - Test Integers" << SRESET);

	int array[] = {101, 202, 33, 44, 43, 42, -10, 92};
	iter(array, sizeof(array)/sizeof(int), &print);
}

void testStrings(int test)
{
	SHOW(SBLUE << test << " - Test Strings" << SRESET);

	std::string array[] =
	{
		"Marte",
		"Jupiter",
		"Saturno",
		"Neptuno",
		"Urano",
		"Venus",
		"Terra",
		"Mercurio"
		"Pluton"
	};
	iter(array, sizeof(array)/sizeof(std::string), &print);
}

void testAlphaChars(int test)
{
	SHOW(SBLUE << test << " - Test Alphabet" << SRESET);

	char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	iter(alphabet, sizeof(alphabet), &print);
}

int main(int argc, char **argv)
{
	int					test;
	std::stringstream	stream;

	if (argc < 2)
		return (E_USE(argv[0]), 1);
	stream << argv[1];
	if (!(stream >> test))
		return (E_NO_INT, 1);
	if (test < 0 || test > 3)
		return (E_LIMITS, 1);
	if (test == 0)
		testIntegers(test);
	else if (test == 1)
		testStrings(test);
	else if (test == 2)
		testAlphaChars(test);
	else
	{
		testIntegers(test);
		testStrings(test);
		testAlphaChars(test);
	}
	return (0);
}
