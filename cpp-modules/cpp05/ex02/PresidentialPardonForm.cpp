
#include "PresidentialPardonForm.hpp"
#include "Exceptions.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
	this->target = "defaultTarget";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& newTarget) : AForm("PresidentialPardonForm", 25, 5)
{
	this->target = newTarget;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other.getName(), other.getGradeToSign(), other.getGradeToExec())
{
	this->target = other.getTarget();
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

std::string PresidentialPardonForm::getTarget() const
{
	return this->target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!this->getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExec())
		throw GradeTooLowException();
	
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}