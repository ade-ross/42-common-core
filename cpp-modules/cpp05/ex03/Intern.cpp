
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
	(void) other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void) other;
	return *this;
}

Intern::~Intern()
{
}

AForm* makeShrubbery(std::string& target)
{
    return new ShrubberyCreationForm(target);
}

AForm* makeRobotomy(std::string& target)
{
    return new RobotomyRequestForm(target);
}

AForm* makePresidential(std::string& target)
{
    return new PresidentialPardonForm(target);
}


AForm* Intern::makeForm(std::string formName, std::string formTarget)
{
	int i = 0;
	std::string forms[3] = {"shrubbery creation", "presidential pardon", "robotomy request"};
	AForm*	(*formCreators[3])(std::string&) = {makeShrubbery, makePresidential, makeRobotomy};

	while(i < 3 && formName != forms[i])
		i++;
	if (i != 3)
	{
		std::cout << "Intern creates " << forms[i] << std::endl;
		return (*formCreators[i])(formTarget);
	}
	else
		std::cout << "provided form name does not exist, possible form names: 'shrubbery creation', 'presidential pardon', 'robotomy request'" << std::endl;
	return NULL;
}
