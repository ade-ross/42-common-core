
#include "Harl.hpp"

enum type
{
	DEBUG,
	INFO,
	WARNING,
	ERROR
};

int	main(int argc, char **argv)
{
	Harl	harl;
	int		i = 0;
	std::string arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	if (argc < 2)
	{
		std::cout << "missing argument" << std::endl;
		return (1);
	}

	while(i < 4 && argv[1] != arr[i])
		i++;

	switch (i)
	{
		case DEBUG:
			harl.complain("DEBUG");
			// fall through
		case INFO:
			harl.complain("INFO");
			// fall through
		case WARNING:
			harl.complain("WARNING");
			// fall through
		case ERROR:
			harl.complain("ERROR");
			break;
	}
	return (0);
}