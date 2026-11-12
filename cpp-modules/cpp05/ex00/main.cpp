
#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat bur0("Pinco", 1);
		std::cout << bur0 << std::endl;
		bur0.promoteBureaucrat();
	} catch (std::exception& e)
	{
		std::cerr << "Caught Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat bur1("Gigio", 150);
		std::cout << bur1 << std::endl;
		bur1.demoteBureaucrat();
	} catch (std::exception& e)
	{
		std::cerr << "Caught Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat bur2("Invalid", 151);
		std::cout << bur2 << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << "Caught Exception: " << e.what() << std::endl;
	}
	

	//only ones that shouldn't throw an exception

	Bureaucrat bur;
	try
	{
		std::cout << bur << std::endl;
		bur.promoteBureaucrat();
		std::cout << "after promotion: " << bur << std::endl;
		bur.demoteBureaucrat();
		std::cout << "after demotion: " << bur << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Caught Exceptionn: " << e.what() << std::endl;
	}

	return 0;
}

