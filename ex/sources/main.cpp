#include "../includes/Array.hpp"
#include "../includes/tests.hpp"

void testDefaultConstructor(int test)
{
	SHOW(SBLUE << test << " - Testing Array Default Constructor" << SRESET);

	Array<int> numbers(10);

	for (size_t i = 0; i < numbers.size(); i++)
		std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
}

void testCopyConstructor(int test)
{
	SHOW(SBLUE << test << " - Test Array Copy Constructor " << SRESET);

	Array<int> numbers(10);
	Array<int> copy(5);

	for (size_t i = 0; i < numbers.size(); i++)
		numbers[i] = 42;

	copy = numbers;
	numbers[0] = 21;
	for (size_t i = 0; i < copy.size(); i++)
		std::cout << "copy[" << i << "] = " << copy[i] << std::endl;
}

void testOutOfBoundsIndexes(int test)
{
	SHOW(SBLUE << test << " - Test Array Invalid Index " << SRESET);
	Array<int> numbers(10);

	try
	{
		numbers[-1] = 0;
	}
	catch (const std::exception &e)
	{
		std::cout << SRED << e.what() << SRESET << '\n';
	}

	try
	{
		numbers[10] = 0;
	}
	catch (const std::exception &e)
	{
		std::cout << SRED << e.what() << SRESET << '\n';
	}
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
		testDefaultConstructor(test);
	else if (test == 1)
		testCopyConstructor(test);
	else if (test == 2)
		testOutOfBoundsIndexes(test);
	else if (test == 3)
	{
		testDefaultConstructor(test);
		testCopyConstructor(test);
		testOutOfBoundsIndexes(test);
	}

	return 0;
}
