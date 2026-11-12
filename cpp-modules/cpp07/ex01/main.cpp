
#include <iostream>
#include <string>
#include "iter.hpp"

template<typename T>
void print(const T& val)
{
	std::cout << val << std::endl;
}

template<typename T>
void increment(T& val)
{
	++val;
}

int main()
{

	std::cout << "int array:" << std::endl;
	int arr[] = {1, 2, 3, 4, 5};
	iter(arr, 5, print<int>);
	iter(arr, 5, increment<int>);
	iter(arr, 5, print<int>);

	std::cout << "\nstring array:" << std::endl;
	std::string arr2[] = {"prova1", "prova2", "prova3"};
	iter(arr2, 3, print<std::string>);

	std::cout << "\nconst int array:" << std::endl;
	const int arr3[] = {10, 20, 30};
	iter(arr3, 3, print<int>);
	//iter(arr, 3, increment<int>); //fallisce perche increment non prende const

	return 0;
}
/*
//correction main
class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  iter( tab, 5, print<const int> );
  iter( tab2, 5, print<Awesome> );

  return 0;
} */
