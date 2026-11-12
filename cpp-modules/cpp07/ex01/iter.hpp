
#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T, typename F>
void iter(T* array, size_t length, F func)
{
	for (size_t i = 0; i < length; ++i)
		func(array[i]);
}

//cancellato in quella pushata non credo serva
/* template <typename T, typename F>
void iter(const T* array, size_t length, F func)
{
	for (size_t i = 0; i < length; ++i)
		func(array[i]);
} */

#endif
