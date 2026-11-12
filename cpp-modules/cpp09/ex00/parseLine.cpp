
#include "BitcoinExchange.hpp"

bool isValidYear(std::string line)
{
	for (int i = 0; i < 4; ++i)
	{
		if (!isdigit(line[i]))
			return false;
	}
	int year = atoi(line.c_str());
	if (year <= 2008)
		return false;
	return true;
}

bool isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDay(std::string line, int month)
{
	int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (isLeapYear(atoi(line.c_str())))
		daysInMonth[1] = 29;

	line = &line[8];
	if (!isdigit(line[0]) || !isdigit(line[1]))
		return false;

	int day = atoi(line.c_str());
	if (day < 1 || day > daysInMonth[month - 1])
		return false;
	return true;
}

bool isValidMonthAndDay(std::string line)
{
	std::string ogline = line;
	line = &line[5];
	if (!isdigit(line[0]) || !isdigit(line[1]))
		return false;

	int month = atoi(line.c_str());
	if (month < 1 || month > 12)
		return false;

	if(!isValidDay(ogline, month))
		return false;
	return true;
}

bool stringToInt(const std::string s, float &result) {
	std::stringstream ss(s);
	ss >> result;

	if (ss.fail() || !ss.eof()) {
		return false;
	}

	if (result > 1000 || result < 0) {
		std::cout <<  "Error: too large a number." << std::endl;
		return false;
	}

	return true;
}

bool parseLine(std::string line, float &lastnumber)
{
	if	(line.size() < 14 || line[4] != '-' || line[7] != '-' || line[10] != ' ' || line[11] != '|' || line[12] != ' ') {
		std::cout << "Error: bad input => " << line << std::endl;
		return false;
	}

	if (!isValidYear(line)) {
		std::cout << "Error: bad input => " << line << std::endl;
		return false;
	}

	if (!isValidMonthAndDay(line)) {
		std::cout << "Error: bad input => " << line << std::endl;
		return false;
	}
	int flag = 1;

	for (size_t i = 13; i < line.size(); i++)
	{
		if (!isdigit(line[i]))
		{
			if (line[i] == '-')
			{
				std::cout << "Error: not a positive number." << std::endl;
				return false;
			}
			else if (line[i] != '.' && flag == 1)
				return false;
			else
				flag = 0;
		}
	}

	if (!stringToInt(&line[13], lastnumber))
		return false;
	return true;
}
