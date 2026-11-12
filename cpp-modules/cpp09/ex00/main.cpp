
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc < 2) {
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	std::ifstream file(argv[1]);

	if (!file.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	std::map<std::string, float> btc_database; 	

	if (!loadDatabase(btc_database))
		return 1;

	std::string line;
	float number;
	std::getline(file, line);
	if (line.substr(0, 4) != "date")
	{
		if (parseLine(line, number))
			searchInDatabase(line.substr(0, 10), btc_database, number);
	}
	while(std::getline(file, line))
	{
		if (parseLine(line, number))
			searchInDatabase(line.substr(0, 10), btc_database, number);
	}

	if (!file.eof()) {
		std::cerr << "error while reading file" << std::endl;
		return 1;
	}

	return 0;
}
