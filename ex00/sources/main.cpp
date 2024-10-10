#include "../includes/whatever.hpp"
#include <iostream>

class SomeClass
{
	public:
		SomeClass(void) : _n(0) {}
		SomeClass( int n ) : _n( n ) {}
		SomeClass & operator= (SomeClass & a) { _n = a._n; return *this; }
		bool operator==( SomeClass const & src ) const { return (this->_n == src._n); }
		bool operator!=( SomeClass const & src ) const{ return (this->_n != src._n); }
		bool operator>( SomeClass const & src ) const { return (this->_n > src._n); }
		bool operator<( SomeClass const & src ) const { return (this->_n < src._n); }
		bool operator>=( SomeClass const & src ) const { return (this->_n >= src._n); }
		bool operator<=( SomeClass const & src ) const { return (this->_n <= src._n); }
		int get_n() const { return _n; }
	private:
		int _n;
};

std::ostream & operator<<(std::ostream & o, const SomeClass &a) { o << a.get_n(); return o; }

int main(void)
{
	{
		int a = 2;
		int b = 3;

		std::cout << "Before: a = " << a << ", b = " << b << std::endl;
		::swap(a, b);
		std::cout << "After: a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

		std::string c = "chaine1";
		std::string d = "chaine2";
		std::cout << "Before: c = " << c << ", d = " << d << std::endl;
		::swap(c, d);
		std::cout << "After: c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}

	std::cout << "===== complex arguments like Classes =====" << std::endl;

	{
		SomeClass a(2), b(4);

		swap(a, b);
		std::cout << a << " " << b << std::endl;
		std::cout << "max( a, b ) = " << max(a, b) << std::endl;
		std::cout << "min( a, b ) = " << min(a, b) << std::endl;
	}

	return 0;
}
