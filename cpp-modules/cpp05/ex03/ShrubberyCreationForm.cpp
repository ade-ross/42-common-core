
#include "ShrubberyCreationForm.hpp"
#include "Exceptions.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("defaultTarget", 145, 137)
{
	this->target = "defaultTarget";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& newTarget) : AForm(newTarget, 145, 137)
{
		this->target = newTarget;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other.getName(), other.getGradeToSign(), other.getGradeToExec())
{
	this->target = other.getTarget();
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

std::string ShrubberyCreationForm::getTarget() const
{
    return this->target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExec())
		throw GradeTooLowException();
	
	std::ofstream file((this->getTarget() + "_shrubbery").c_str());
	if (!file)
    	throw std::runtime_error("Could not open file");
    file << "         &&& &&  & &&\n"
			"      && &\\/&\\|& ()|/ @, &&\n"
			"      &\\/(/&/&||/& /_/)_&/_&\n"
			"   &() &\\/&|()|/&\\/ '%\" & ()\n"
			"  &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
			"&&   && & &| &| /& & % ()& /&&\n"
			" ()&_---()&\\&\\|&&-&&--%---()~\n"
			"     &&     \\|||\n"
			"             |||\n"
			"             |||\n"
			"             |||\n"
			"       , -=-~  .-^- _\n";
    file.close();
}