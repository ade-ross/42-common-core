
#include "AForm.hpp"
#include "Exceptions.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("defaultName"), isSigned(false), gradeToSign(150), gradeToExec(150)
{
}

AForm::AForm(const std::string& newName, int newGradeToSign, int newGradeToExec) : name(newName), isSigned(false)
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

AForm::AForm(const AForm& other) : name(other.name), isSigned(other.isSigned)
{
	this->gradeToSign = other.gradeToSign;
	this->gradeToExec = other.gradeToExec;
}

AForm& AForm::operator=(const AForm& other)
{
	if(this != &other)
	{
		(std::string) this->name = other.name;
		this->gradeToSign = other.gradeToSign;
		this->gradeToExec = other.gradeToExec;
	}
	return *this;
}

AForm::~AForm()
{
}

std::string AForm::getName() const
{
	return this->name;
}
int AForm::getGradeToSign() const
{
	return this->gradeToSign;
}
int AForm::getGradeToExec() const
{
	return this->gradeToExec;
}

bool AForm::getIsSigned() const
{
	return this->isSigned;
}

void AForm::beSigned(Bureaucrat& bur)
{
	if (bur.getGrade() <= gradeToSign)
		this->isSigned = true;
	else
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, AForm& f)
{
	os << "AForm: " << f.getName() << " with grade :" << f.getGradeToSign() << " to be signed and with grade: " << f.getGradeToExec() << " to be executed is ";
	if (f.getIsSigned())
		os << "signed";
	else
		os << "not signed";
	return os;
}
