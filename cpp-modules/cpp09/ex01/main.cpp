
#include "RPN.hpp"

int main(int argc, char *argv[])
{
	std::string line;

	if (argc < 2)
	{
		std::cerr << "missing argument" << std::endl;
		return 1;
	}
	if (argc > 2)
	{
		std::cerr << "too many arguments" << std::endl;
		return 1;
	}

	line = argv[1];

	if (!checkLineIsValid(line))
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	std::stack<int> numbers;
	if (!executeRPN(numbers, line))
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	std::cout << numbers.top() << std::endl;
	return 0;
}
