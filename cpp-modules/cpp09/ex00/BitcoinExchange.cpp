
#include "BitcoinExchange.hpp"

void searchInDatabase(std::string lineToSearch, std::map<std::string, float> btc_values, float numberToMultiply)
{
	std::map<std::string, float>::iterator it;
	it = btc_values.upper_bound(lineToSearch);

	if (it != btc_values.begin())
		it--;

	std::cout << lineToSearch<< " => " << numberToMultiply << " = " << (numberToMultiply * it->second) << std::endl;
}

bool loadDatabase(std::map<std::string, float> & db)
{
	std::ifstream file("data.csv");

	if (!file.is_open()) {
		std::cerr << "Error: could not open database file." << std::endl;
		return false;
	}

	std::string line;

	std::getline(file, line);
	while(std::getline(file, line))
	{
		std::stringstream ss(&line[11]);
		float value;
		ss >> value;
		db[line.substr(0, 10)] = value;
	}

	if (!file.eof()) {
		std::cerr << "error while reading database file" << std::endl;
		return false;
	}
	return true;
}