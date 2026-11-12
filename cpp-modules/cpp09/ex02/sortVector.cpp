
#include "PmergeMe.hpp"

void binaryInsert(std::vector<int> & numbers, std::vector<int> & temp, int max, int level)
{
	//maxx è massima pos dove si puo inserire temp
	if (max == 0 || max - level + 1 == 0)
		return;

	int left = 1;
	int right = max / level;
	int avg = 0;
	while (left <= right)
	{
		avg = left + ((right - left) / 2);
		if (numbers[avg * level - 1] == temp[level - 1])
		{
			right = avg;
			break;
		}
		else if (numbers[avg * level - 1] < temp[level - 1])
			left = avg + 1;
		else
			right = avg - 1;
	}

	right = right * level;
	while (!temp.empty() || level - 1 >= 0)
	{
		numbers.insert(numbers.begin() + (right), temp[level - 1]);
		temp.erase(temp.begin() + level - 1);
		level--;
	}
}

void insertLosers(std::vector<int> & numbers, int level, int *jacobsthal)
{
	//qui max e la posizione dell'ultimo numero che va inserito (l'ultimo loser)(mi pare)
	if (static_cast<int>(numbers.size()) == level)
		return ;

	int i = 2;
	int m = 1;
	int max;
	int min;
	int lsize = numbers.size() / (2 * level);
	int sizee;

	while (jacobsthal[i] < lsize)
	{
		max = jacobsthal[i] * (2 * level) + level - 1 - (2 * level);
		min = jacobsthal[i - 1] * (2 * level) + level - 1 - (2 * level);

		int r = 0;
		sizee = jacobsthal[i] - jacobsthal[i - 1];
		std::vector<int> temp1[sizee];
		while(max > min)
		{

			m = max - level + 1;
			int initialM = m;
			while(m <= max)
			{
				temp1[r].push_back(numbers[initialM]);
				numbers.erase(numbers.begin() + initialM);
				m++;
			}
			r++;

			max = max - (2 * level);
		}
		int nn = 0;
		max = jacobsthal[i] * (2 * level) + level - 1 - (2 * level);
		max = max - (sizee * level) + 1;
		while (nn < sizee)
		{
			binaryInsert(numbers, temp1[nn], max, level);
			nn++;
		}
		i++;
	}

	if (((numbers.size() / (2 * level)) - jacobsthal[i - 1]) > 0)
	{
		max = (numbers.size() / (2 * level)) * (2 * level) + level - 1 - (2 * level);
		min = jacobsthal[i - 1] * (2 * level) + level - 1 - (2 * level);

		sizee = (numbers.size() / (2 * level)) - jacobsthal[i - 1];
		std::vector<int> temp2[sizee];
		int r = 0;
		while(max > min)
		{

			m = max - level + 1;
			int initialM = m;
			while(m <= max)
			{
				temp2[r].push_back(numbers[initialM]);
				numbers.erase(numbers.begin() + initialM);
				m++;
			}
			r++;
			max = max - (2 * level);
		}
		int ii = 0;
		max = jacobsthal[i - 1] * (2 * level) + level - 1 - (2 * level);
		max = max + (sizee * level) + 1;
		while (ii < sizee)
		{
			binaryInsert(numbers, temp2[ii], max, level);
			ii++;
		}
	}
}

std::vector<int> sortVector(std::vector<int> numbers, int *jacobsthal, size_t level)
{

	if (numbers.size() == level)
		return numbers;
	size_t i;

	std::vector<int> oddNum;
	int flag = -1;
	if (numbers.size() % (2 * level) != 0)
	{
		size_t z = 0;
		int sizeWithOddNumbrs = numbers.size();
		while (z < level)
		{
			oddNum.push_back(numbers[sizeWithOddNumbrs - level]);
			numbers.erase(numbers.begin() + sizeWithOddNumbrs - level);
			z++;
		}
		flag = 1;
	}

	for (i = level; i < numbers.size(); i += 2 * level)
	{
		if (numbers[i - 1] > numbers[i + level - 1])
		{
			std::rotate(numbers.begin() + i - level, numbers.begin() + i , numbers.begin() + i + level);
		}
	}

	numbers = sortVector(numbers, jacobsthal, level * 2);

	insertLosers(numbers, level, jacobsthal);

	if (flag == 1)
	{
		binaryInsert(numbers, oddNum, numbers.size(), level);
	}
	return numbers;
}