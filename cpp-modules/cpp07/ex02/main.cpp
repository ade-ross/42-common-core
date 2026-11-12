
#include <iostream>
#include "Array.hpp"

//my main
int main()
{
	Array<int> a;
	std::cout << "a.size() = " << a.size() << std::endl;

	Array<int> b(10);
	for (unsigned int i = 0; i < b.size(); ++i) {
		b[i] = (i + 1) * 10;
		std::cout << "b[" << i << "] = " << b[i] << std::endl;
	}

	Array<int> c(b);
	std::cout << "Copy of b into c:" << std::endl;
	for (unsigned int i = 0; i < c.size(); ++i) {
		std::cout << "c[" << i << "] = " << c[i] << std::endl;
	}

	b[0] = 999;
	std::cout << "After changing b[0] = "<< b[0] << ", c[0] = " << c[0] << std::endl;

	Array<int> d;
	d = c;
	std::cout << "Assigned c to d:" << std::endl;
	for (unsigned int i = 0; i < d.size(); ++i) {
		std::cout << "d[" << i << "] = " << d[i] << std::endl;
	}

	try {
		std::cout << b[-10] << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}

/*
// given main also present in correction
#include <iostream>
#include <stdlib.h>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}
 */

/*
template <typename T>
class Array
{
private:
	T *_data;
	unsigned int _size;
public:
	Array();
	Array(unsigned int new_size);
	Array(const Array& other);
	Array& operator=(const Array& other);
	~Array();

	const T& operator[](int index) const;
	T& operator(int index);
	unsigned int size() const;
	class OutOfBoundsException : public std::exception
	{
		public:
			virtual const char * what() const throw();
	}
};

 */
