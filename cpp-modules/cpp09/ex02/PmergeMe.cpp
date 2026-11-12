
#include "PmergeMe.hpp"

int *Jacobsthal(int *arr, int size)
{
	int i = 2;

	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 3;
	while (i < size)
	{
		i++;
		arr[i] = arr[i - 1] + 2 * arr[i - 2];
	}
	return arr;
}

int64_t timeInMicroseconds(const timeval& t)
{
	return static_cast<int64_t>(t.tv_sec) * static_cast<int64_t>(1000000) + t.tv_usec;
}
