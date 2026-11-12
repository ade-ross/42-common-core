#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

const char* NotFoundException::what() const throw() {
	return "Value not found in container.";
}

int main() {
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);

	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);

	try {
		std::vector<int>::iterator it = easyfind(vec, 2);
		std::cout << "Found in vector: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Vector: " << e.what() << std::endl;
	}

	try {
		std::list<int>::iterator it = easyfind(lst, 32);
		std::cout << "Found in list: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << "List: " << e.what() << std::endl;
	}

	return 0;
}
