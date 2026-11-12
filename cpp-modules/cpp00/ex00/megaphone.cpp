
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}

	for (int i = 1; i < argc; ++i)
	{
		std::string arg = argv[i];
		for (size_t j = 0; j < arg.length(); ++j)
		{
			if (arg[j] >= 'a' && arg[j] <= 'z') 
				std::cout << (char) (arg[j] - 32);
			else
				std::cout << arg[j];
		}
	}
	std::cout << endl;
	return 0;
}

