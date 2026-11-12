
#include "Form.hpp"
#include "Exceptions.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("defaultName"), isSigned(false), gradeToSign(150), gradeToExec(150)
{
}

Form::Form(const std::string& newName, int newGradeToSign, int newGradeToExec) : name(newName), isSigned(false)
{
	if (newGradeToSign < 1 || newGradeToExec < 1)
	{
		throw GradeTooHighException();
	}
	if (newGradeToSign > 150 || newGradeToExec > 150)
	{
		throw GradeTooLowException();
	}
	this->gradeToSign = newGradeToSign;
	this->gradeToExec = newGradeToExec;
}

Form::Form(const Form& other) : name(other.name), isSigned(other.isSigned)
{
	this->gradeToSign = other.gradeToSign;
	this->gradeToExec = other.gradeToExec;
}

Form& Form::operator=(const Form& other)
{
	if(this != &other)
	{
		(std::string) this->name = other.name;
		this->gradeToSign = other.gradeToSign;
		this->gradeToExec = other.gradeToExec;
	}
	return *this;
}

Form::~Form()
{
}

std::string Form::getName() const
{
	return this->name;
}
int Form::getGradeToSign() const
{
	return this->gradeToSign;
}
int Form::getGradeToExec() const
{
	return this->gradeToExec;
}

bool Form::getIsSigned() const
{
	return this->isSigned;
}

void Form::beSigned(Bureaucrat& bur)
{
	if (bur.getGrade() <= gradeToSign)
		this->isSigned = true;
	else
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, Form& f)
{
	os << "Form: " << f.getName() << " grade to be signed: " << f.getGradeToSign() << " grade to be executed: " << f.getGradeToExec() << " is ";
	if (f.getIsSigned())
		os << "signed";
	else
		os << "not signed";
	return os;
}
