#include "../includes/iter.hpp"
#include "../includes/tests.hpp"

class SomeArray
{
	public:
		SomeArray( void ) : _n( 7 ) { return; }
		int get( void ) const { return this->_n; }
	private:
		int _n;
};

std::ostream & operator<<( std::ostream & out, SomeArray const & Awe )
{
	out << Awe.get();
	return out;
}

void testIntegers(int test)
{
	SHOW(SBLUE << test << " - Test Integers" << SRESET);

	int array[] = {101, 202, 33, 44, 43, 42, -10, 92};
	iter(array, sizeof(array)/sizeof(int), &print);
}

void testStrings(int test)
{
	SHOW(SBLUE << test << " - Test Strings" << SRESET);

	std::string sArray[] =
	{
		"Marte",
		"Jupiter",
		"Saturno",
		"Neptuno",
		"Urano",
		"Venus",
		"Terra",
		"Mercurio",
		"Pluton"
	};
	iter(sArray, sizeof(sArray)/sizeof(std::string), &print);
}

void testAlphaChars(int test)
{
	SHOW(SBLUE << test << " - Test Alphabet" << SRESET);

	char cArray[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	iter(cArray, sizeof(cArray) - 1, print<const char>);
}

void testClassArray(int test)
{
	SHOW(SBLUE << test << " - Test Class Array" << SRESET);

	SomeArray classArray[5];
	iter(classArray, 5, &print);
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
	if (test < 0 || test > 4)
		return (E_LIMITS, 1);
	if (test == 0)
		testIntegers(test);
	else if (test == 1)
		testStrings(test);
	else if (test == 2)
		testAlphaChars(test);
	else if (test == 3)
	{
		testClassArray(test);
	}
	else
	{
		testIntegers(test);
		testStrings(test);
		testAlphaChars(test);
		testClassArray(test);
	}
	return (0);
}
