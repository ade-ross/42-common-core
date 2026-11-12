
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{

	//throws exception
	try
	{
		Bureaucrat a("Pinco2", 112);
		Form f("form2", 24, 12);
		f.beSigned(a);
	} catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat a("Pinco2", 112);
		Form f("form2", 24, 12);
		a.signForm(f);
	} catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	//doesn't throw exception
	try
	{
		Bureaucrat b("Pinco", 11);
		Form f("form1", 24, 12);
		std::cout << f << std::endl;
		b.signForm(f);
	} catch (std::exception& e)
	{
		std::cerr << "Caught Exception: " << e.what() << std::endl;
	}

}

