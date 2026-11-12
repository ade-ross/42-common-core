#include "PmergeMe.hpp"

void skipSpaces(char * line, int & i)
{
	while (line[i] != '\0' && line[i] == ' ')
		i++;
}

bool parsing(char** argv, std::vector<int> & numbersv, std::deque<int> & numbersd)
{
	int i = 1;
	int j = 0;
	while (argv[i])
	{
		j = 0;
		skipSpaces(argv[i], j);
		while (argv[i][j] != '\0')
		{
			numbersv.push_back(atoi(&argv[i][j]));
			numbersd.push_back(atoi(&argv[i][j]));
			skipSpaces(argv[i], j);
			if (argv[i][j] != '\0' && (argv[i][j] == '+') && isdigit(argv[i][j + 1]))
				j++;
			while(argv[i][j] != '\0' && isdigit(argv[i][j]))
				j++;
			if (argv[i][j] != '\0' && argv[i][j] != ' ' && !((argv[i][j] == '+') && isdigit(argv[i][j + 1])))
			{
				std::cerr << "Error" << std::endl;
				return false;
			}
			skipSpaces(argv[i], j);
		}
		i++;
	}
	return true;
}
