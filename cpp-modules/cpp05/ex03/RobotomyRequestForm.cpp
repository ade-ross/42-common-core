
#include "RobotomyRequestForm.hpp"
#include "Exceptions.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("defaultTarget", 72, 45)
{
	this->target = "defaultTarget";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& newTarget) : AForm(newTarget, 72, 45)
{
	this->target = newTarget;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other.getName(), other.getGradeToSign(), other.getGradeToExec())
{
	this->target = other.getTarget();
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}
std::string RobotomyRequestForm::getTarget() const
{
    return this->target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!this->getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExec())
		throw GradeTooLowException();
	
	std::srand(std::time(0));
	std::cout << "~~Drilling noises zzz~~" << std::endl;
	if(std::rand() % 2  == 0)
		std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
	else
		std::cout <<  "robotomy on " << this->getTarget() << " failed" << std::endl;
}