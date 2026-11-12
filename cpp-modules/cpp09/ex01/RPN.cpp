
#include "RPN.hpp"

bool checkLineIsValid(std::string & line)
{
	for (int i = 0; line[i]; i++)
	{
		if (!(isdigit(static_cast<unsigned char>(line[i])) || line[i] == ' ' || line[i] == '-' || line[i] == '+' || line[i] == '*' || line[i] == '/'))
			return false;
	}
	return true;
}

void skipSpaces(std::string line, int & i)
{
	while (line[i] && (line[i] == ' '))
		i++;
}

bool getNumFromStack(std::stack<int> & numbers, int & number)
{
	if (numbers.empty())
		return false;

	number = numbers.top();
	numbers.pop();
	return true;
}

bool executeRPN(std::stack<int> & numbers, std::string & line)
{
	std::stringstream ss(line);
	int newNumber;
	int tempNum;
	char skip;
	int i = 0;

	while (line[i])
	{
		skipSpaces(line, i);

		if (isdigit(static_cast<unsigned char>(line[i])))
		{
			ss >> newNumber;
			if (newNumber > 9)
				return false;
			numbers.push(newNumber);
			i++;
		}
		else
		{
			ss >> skip;
			i++;

			if (!getNumFromStack(numbers, tempNum))
				return false;
			if (!getNumFromStack( numbers, newNumber))
				return false;
			if (skip == '+')
				newNumber += tempNum;
			else if (skip == '-')
				newNumber -= tempNum;
			else if (skip == '*')
				newNumber *= tempNum;
			else if (skip == '/' && tempNum != 0)
				newNumber /= tempNum;
			else if (skip == '/' && tempNum == 0)
				return false;
			numbers.push(newNumber);
		}
		if (line[i] != '\0' && line[i] != ' ')
		{
			return false;
		}

		skipSpaces(line, i);
	}

	if (numbers.empty() || numbers.size() != 1)
		return false;
	return true;
}