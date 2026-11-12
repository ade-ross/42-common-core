
#include "Bureaucrat.hpp"
#include "AForm.hpp"
/* #include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp" */
#include "Intern.hpp"

int main()
{
	Intern randomIntern;

	//wrong form
	AForm* wrongForm;
	wrongForm = randomIntern.makeForm("wrong request", "Bender");
	(void)wrongForm;


	Bureaucrat strong("Strong", 1);
	
	//subject
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");

	rrf->beSigned(strong);
	rrf->execute(strong);
	delete rrf;
} 

