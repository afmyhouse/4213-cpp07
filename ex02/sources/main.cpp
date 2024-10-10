#include "../includes/Array.hpp"
#include "../includes/tests.hpp"

// Test function to demonstrate functionality

void testVoidConstructor(int test)
{
	SHOW(SBLUE << test << " - Testing Array Void Constructor" << SRESET);

	Array<int> numbers;

	std::srand(time(0));
	for (size_t i = 0; i < numbers.size(); i++)
		numbers[i] = std::rand() % 100;
	for (size_t i = 0; i < numbers.size(); i++)
		std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
	std::cout << "numbers.size() = " << numbers.size() << std::endl;
	std::cout << "Array & " << &numbers << std::endl;
}

void testParametricConstructor(int test)
{
	SHOW(SBLUE << test << " - Testing Array Parametric Constructor" << SRESET);

	Array<int> numbers(10);

	std::srand(time(0));
	for (size_t i = 0; i < numbers.size(); i++)
		numbers[i] = std::rand() % 100;
	for (size_t i = 0; i < numbers.size(); i++)
		std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
}

void testCopyConstructor(int test)
{
	SHOW(SBLUE << test << " - Test Array Copy Constructor" << SRESET);

	Array<int> original(10);

	std::srand(time(0));
	for (size_t i = 0; i < original.size(); i++)
		original[i] = std::rand() % 100;
	for (size_t i = 0; i < original.size(); i++)
		std::cout << "original[" << i << "] = " << original[i] << std::endl;

	Array<int> aCopy(original);
	for (size_t i = 0; i < aCopy.size(); i++)
		std::cout << "copy[" << i << "] = " << aCopy[i] << std::endl;
}

void testAssignConstructor(int test)
{
	SHOW(SBLUE << test << " - Test Array Assigment Constructor " << SRESET);

	Array<int> original(10);

	std::srand(time(0));
	for (size_t i = 0; i < original.size(); i++)
		original[i] = std::rand() % 100;
	for (size_t i = 0; i < original.size(); i++)
		std::cout << "original[" << i << "] = " << original[i] << std::endl;

	Array<int> aCopy = original;
	for (size_t i = 0; i < aCopy.size(); i++)
		std::cout << "copy[" << i << "] = " << aCopy[i] << std::endl;
}

void testComplexConstructor(int test)
{
	SHOW(SBLUE << test << " - Testing Complex Array Constructor" << SRESET);
	const char* stars[] = {"Cygni", "Struve", "Groombridge", "Lalande", "Keid", "Kapteyn", "Kruger", "Ross"};
	const char* planets[] = {"Marte", "Jupiter", "Saturno", "Neptuno", "Urano", "Venus", "Terra", "Mercurio", "Pluton"};
	const char* constellations[] = {"Andromeda", "Cassiopeia", "Orion", "Ursa Major", "Ursa Minor", "Draco", "Lyra", "Cygnus"};

	Array<std::string> aPlanets(9);
	Array<std::string> aStars(8);
	Array<std::string> aConstellations(8);

	for (size_t i = 0; i < aPlanets.size(); i++) {
		aPlanets[i] = planets[i];
		std::cout << "planets[" << i << "] = " << aPlanets[i] << std::endl;
	}
	for (size_t i = 0; i < aStars.size(); i++) {
		aStars[i] = stars[i];
		std::cout << "stars[" << i << "] = " << aStars[i] << std::endl;
	}
	for (size_t i = 0; i < aConstellations.size(); i++) {
		aConstellations[i] = constellations[i];
		std::cout << "constellations[" << i << "] = " << aConstellations[i] << std::endl;
	}

	Array< Array<std::string> > nearSpace(3);
	nearSpace[0] = aPlanets;
	nearSpace[1] = aStars;
	nearSpace[2] = aConstellations;

	// Show nearSpace contents
	for (size_t i = 0; i < nearSpace.size(); i++)
	{
		for (size_t j = 0; j < nearSpace[i].size(); j++)
			std::cout << "nearSpace[" << i << "][" << j << "] = " << nearSpace[i][j] << std::endl;
	}
}
void testInvalidAccess(int test)
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
	if (test < 0 || test > TESTNUM)
		return (E_LIMITS, 1);
	if (test == 0)
		testVoidConstructor(test);
	else if (test == 1)
		testParametricConstructor(test);
	else if (test == 2)
		testCopyConstructor(test);
	else if (test == 3)
		testAssignConstructor(test);
	else if (test == 4)
		testComplexConstructor(test);
	else if (test == 5)
		testInvalidAccess(test);
	else if (test == 6)
	{
		testVoidConstructor(test);
		testParametricConstructor(test);
		testCopyConstructor(test);
		testAssignConstructor(test);
		testComplexConstructor(test);
		testInvalidAccess(test);
	}
	return 0;
}
