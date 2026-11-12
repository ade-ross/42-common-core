
#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error" << std::endl;
		std::cerr << "missing arguments" << std::endl;
		return 1;
	}
	std::vector<int> numbersv;
	std::deque<int> numbersd;

	if (!parsing(argv, numbersv, numbersd))
		return 1;

	std::cout << "Before: ";
	size_t sizee = numbersd.size();
	/* if (sizee > 4)
		sizee = 4; */
	for (size_t i = 0; i < sizee; ++i) {
		std::cout << numbersd[i] << " ";
	}
	/* if (numbersd.size() > 4)
		std::cout << "[...]"; */
	std::cout << std::endl;

	int size = numbersv.size();
	if (size < 3)
		size = 3;
	int arr[size];
	int *jacobst = Jacobsthal(arr, numbersv.size());

	timeval startv, startd, endv, endd;

	gettimeofday(&startv, NULL);

	numbersv = sortVector(numbersv, jacobst, 1);

	gettimeofday(&endv, NULL);


	gettimeofday(&startd, NULL);

	numbersd = sortDeque(numbersd, jacobst, 1);

	gettimeofday(&endd, NULL);

	std::cout << "After: ";
	sizee = numbersd.size();
	/* if (sizee > 4)
		sizee = 4; */
	for (size_t i = 0; i < sizee; ++i) {
		std::cout << numbersd[i] << " ";
	}
	/* if (numbersd.size() > 4)
		std::cout << "[...]"; */
	std::cout << std::endl;

/* size_t i = 1;
 int flag = 1;
 	while (i < numbersv.size())
	{
		if (numbersv[i - 1] > numbersv[i] )
		{
			std::cout << " ERRROREEE i: " << i << "num : " << numbersv[i] << std::endl;
			flag = 0;
		}
		i++;
	}

	while (i < numbersd.size())
	{
		if (numbersd[i - 1] > numbersd[i] )
		{
			std::cout << " ERRROREEE i: " << i << "num : " << numbersd[i] << std::endl;
			flag = 0;
		}
		i++;
	} */

	int64_t vectorDuration =  timeInMicroseconds(endv) - timeInMicroseconds(startv);
	std::cout << "Time to process a range of " << numbersv.size() << " elements with std::vector : " << vectorDuration << " us" << std::endl;

	int64_t dequeDuration =  timeInMicroseconds(endd) - timeInMicroseconds(startd);
	std::cout << "Time to process a range of " << numbersd.size() << " elements with std::deque : " << dequeDuration << " us" << std::endl;
	
	/* if (flag == 1)
		std::cout << "finish! YEEE GIUSTOO" << std::endl; */
}
