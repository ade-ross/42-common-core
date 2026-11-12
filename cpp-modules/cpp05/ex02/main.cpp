
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	ShrubberyCreationForm a("Form1");
	RobotomyRequestForm b("Form2");
	PresidentialPardonForm c("Form3");

	Bureaucrat al("Al", 2);

	//try to execute unsigned forms throws exception
	try
	{
		a.execute(al);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		al.executeForm(b);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	//try to execute form with burocrat with insufficient grade
	Bureaucrat weak("Weak", 144);

	//sign forms
	a.beSigned(al);
	b.beSigned(al);
	c.beSigned(al);

	//try to execute form with burocrat with insufficient grade
	try
	{
		a.execute(weak);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		weak.executeForm(b);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	al.executeForm(a);//shrubbery

	b.execute(al);//robotomy

	c.execute(al);//presidential pardon
}

