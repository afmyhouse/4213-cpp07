# include "../includes/Array.hpp"
//# include "../includes/Array.tpp"
# include "../includes/tests.hpp"
# include <iostream>
# include <sstream>

// template <class T>
// class Array
// {
// 	private:
// 		T *array;
// 		unsigned int n;

// 	public:
// 		//! Constructors and destructor
// 		Array();
// 		Array(unsigned int n);
// 		Array(const Array& copy);
// 		~Array();

// 		//! Member functions
// 		unsigned int size(void) const;

// 		//! Operator overloading
// 		Array& operator=(const Array& right);
// 		T& operator[](unsigned int index);

// 	class IndexOutOfBoundsException : public std::exception
// 	{
// 		public:
// 			virtual const char* what() const throw();
// 	};
// };
// /*
// REMARKS
// Default Constructor Initialization: In the default constructor, i'm allocating
// an array of size 0, which is technically fine but unnecessary.
// I could simply set the pointer to NULL for clarity.

// template <class T>
// Array<T>::Array() : array(NULL), n(0)
// {
// }
// */

// //! Default constructor
// template <class T>
// Array<T>::Array() : n(0)
// {
// 	this->array = new T[0];
// }

// //! Parameterized constructor
// template <class T>
// Array<T>::Array(unsigned int n) : n(n)
// {
// 	this->array = new T[this->n];
// 	for (unsigned int i = 0; i < this->n; i++)
// 		this->array[i] = T();   // Default construct each element
// }

// //! Copy constructor
// template <class T>
// Array<T>::Array(const Array& copy)
// {
// 	this->array = NULL;
// 	*this = copy;
// }

// //! Destructor
// template <class T>
// Array<T>::~Array()
// {
// 	delete [] array;
// }

// //! Return the size of the array
// template <class T>
// unsigned int Array<T>::size(void) const
// {
// 	return (this->n);
// }

// //! Assignment operator overload
// template <class T>
// Array<T>& Array<T>::operator =(const Array<T>& right)
// {
// 	if (this == &right)
// 		return (*this);

// 	delete [] this->array;

// 	this->n = right.n;
// 	this->array = new T[this->n];
// 	for (unsigned int i = 0; i < this->n; i++)
// 		this->array[i] = right.array[i];

// 	return (*this);
// }

// //! Operator [] overload
// template <class T>
// T& Array<T>::operator [](unsigned int index)
// {
// 	if (index >= this->n) //* unsigned int is never < 0
// 		throw Array<T>::IndexOutOfBoundsException();
// 	return (this->array[index]);
// }

// //! Exception handling for out-of-bounds access
// template <class T>
// const char* Array<T>::IndexOutOfBoundsException::what() const throw()
// {
// 	return ("Array Exception: index out of bounds");
// }

// Test function to demonstrate functionality
void testComplexConstructor(void)
{
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

int main()
{
	testComplexConstructor();
	return 0;
}