
#include "Array.hpp"

//da fare se voglio
#ifndef ARRAY_TPP
# define ARRAY_TPP

// Default constructor
template<typename T>
Array<T>::Array() : _data(new T[0]()), _size(0) {}

// Constructor with size
template<typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]()), _size(n) {}

template<typename T>
Array<T>::Array(int n) {
	if (n < 0)
		throw OutOfBoundsException();
	_data = new T[n]();
	_size = n;
}

// Copy constructor
template<typename T>
Array<T>::Array(const Array& other) : _data(NULL), _size(0) {
	*this = other;
}

// Assignment operator
template<typename T>
Array<T>& Array<T>::operator=(const Array& other) {
	if (this != &other) {
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
template<typename T>
Array<T>::~Array() {
	delete[] _data;
}

// Subscript operator (non-const)
template<typename T>
T& Array<T>::operator[](int index) {
	if (index < 0 || static_cast<unsigned int>(index) >= _size)
		throw OutOfBoundsException();
	return _data[index];
}

// Subscript operator (const)
template<typename T>
const T& Array<T>::operator[](int index) const {
	if (index < 0 || static_cast<unsigned int>(index) >= _size)
		throw OutOfBoundsException();
	return _data[index];
}

// size()
template<typename T>
unsigned int Array<T>::size() const {
	return _size;
}

// what() for exception
template<typename T>
const char* Array<T>::OutOfBoundsException::what() const throw() {
	return "Index out of bounds";
}

#endif
