
#include "check_all_initial_numbers_are_present_in_result.hpp"

//controlla che tutti i numeri iniziali siano presenti alla fine, prende prima numeri sortati poi numeri non sortati(mi pare)
int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: missing arguments" << std::endl;
		return 1;
	}
	std::vector<int> numbersv;
	std::deque<int> numbersd;

	if (!parsing2(argv, numbersv, numbersd))
		return 1;
	if (numbersd.size() < 2 || numbersv.size() < 2)
	{
		std::cerr << "Error: too few arguments" << std::endl;
		return 1;
	}
	for (size_t i = 0; i < numbersv.size(); ++i) {
		std::cout << numbersv[i] << " ";
	}
	std::cout << std::endl;
	/* std::cout << "number0: ";
	for (size_t i = 0; i < numbersv.size(); ++i) {
		std::cout << " i: " << i << "  " << numbersv[i] << " ";
	} */
	/* 
	int arrrrr[50] = {
		60781, 37927, 19649, 99914, 44235, 22324, 20271, 64647, 86094, 17025, 785, 41411, 32891, 95026, 76815, 82057, 53116, 46864, 70264, 83449, 63738, 31342, 22657, 67743, 5407, 86910, 16245, 90438, 87644, 8742, 26490, 29967, 67685, 82201, 64343, 77406, 12134, 87028, 67654, 38467, 75057, 92881, 14865, 45433, 98727, 99154, 67801, 64883, 89433, 33679
	}; */

	argv = &argv[1];
	std::vector<int> arrrrr;
	if (!parsing2(argv, arrrrr, numbersd))
		return 1;
	int l = 0;
	int flag = 1;
	while (l < 50)
	{
		std::vector<int>::iterator it = std::find(numbersv.begin(), numbersv.end(), arrrrr[l]);

		if (it != numbersv.end()) {
		} else {
			std::cout << "Indice: " << l << " num: " << arrrrr[l] << std::endl;
			flag = 0;
		}
		l++;
	}
	if (flag == 1)
		std::cout << " Corretto!!" << std::endl;
	std::cout << std::endl;
}
//60781 37927 19649 99914 44235 22324 20271 64647 86094 17025 785 41411 32891 95026 76815 82057 53116 46864 70264 83449 63738 31342 22657 67743 5407 86910 16245 90438 87644 8742 26490 29967 67685 82201 64343 77406 12134 87028 67654 38467 75057 92881 14865 45433 98727 99154 67801 64883 89433 33679
// 98727

// numbers3: 26490 29967 785 41411 22324 44235 14865 45433 46864 53116 37927 60781 31342 63738 20271 64647 38467 67654 22657 67743 64883 67801 64343 77406 76815 82057 67685 82201 70264 83449 17025 86094 5407 86910 12134 87028 8742 87644 33679 89433 16245 90438 75057 92881 32891 95026 98727 99154 19649 99914
// numbers2: 26490 29967 785 41411 22324 44235 14865 45433 46864 53116 37927 60781 31342 63738 20271 64647 38467 67654 22657 67743 64883 67801 64343 77406 76815 82057 67685 82201 70264 83449 17025 86094 5407 86910 12134 87028 8742 87644 33679 89433 16245 90438 75057 92881 32891 95026 98727 99154 19649 99914  level: 1 i: 2 max: 4 min: 0
//  sizee: 2
// temp[0], i: 2
