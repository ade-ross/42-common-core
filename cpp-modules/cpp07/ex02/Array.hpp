
#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template<typename T>
class Array {
	private:
		T*				_data;
		unsigned int	_size;

	public:
		Array();
		Array(unsigned int n);
		Array(int n);
		Array(const Array& other);
		Array& operator=(const Array& other);
		~Array();

		T& operator[](int index);
		const T& operator[](int index) const;
		unsigned int size() const;

		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

# include "Array.tpp"

#endif

/* 
#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template<typename T>
class Array {
	private:
		T*				_data;
		unsigned int	_size;

	public:
		// Default constructor
		Array() : _data(NULL), _size(0) {}

		// Parameterized constructor
		Array(unsigned int n) : _data(new T[n]()), _size(n) {}

		Array(int n) {
			if (n < 0)
				throw OutOfBoundsException();
			_data = new T[n]();
			_size = n;
		}

		// Copy constructor
		Array(const Array& other) : _data(NULL), _size(0) {
			*this = other;
		}

		// Assignment operator
		Array& operator=(const Array& other) {
			if (this != &other)
			{
				delete[] _data;
				_size = other._size;
				_data = new T[_size];
				for (unsigned int i = 0; i < _size; ++i) {
					_data[i] = other._data[i];
				}
			}
			return *this;
		}

		// Destructor
		~Array() {
			delete[] _data;
		}

		// Subscript operator (non-const)
		T& operator[](int index) {
			if (index < 0 || static_cast<unsigned int>(index) >= _size)
				throw OutOfBoundsException();
			return _data[index];
		}

		// Subscript operator (const)
		const T& operator[](int index) const {
			if (index < 0 || static_cast<unsigned int>(index) >= _size)
				throw OutOfBoundsException();
			return _data[index];
		}

		// Size function
		unsigned int size() const {
			return _size;
		}

		// Exception class
		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Index out of bounds";
				}
		};
};

#endif */
