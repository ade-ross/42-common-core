
#include <iostream>

int	main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string* st = &str;
	std::string& s = str;

	std::cout << "string address is: " << &str << std::endl;
	std::cout << "pointer address is: " << st << std::endl;
	std::cout << "reference address is: " << &s << std::endl;

	std::cout << "string value is: " << str << std::endl;
	std::cout << "pointer value is: " << *st << std::endl;
	std::cout << "reference value is: " << s << std::endl;
}