
#include "Bureaucrat.hpp"
#include "Exceptions.hpp"

Bureaucrat::Bureaucrat() : name("defaultName"), grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string& name, int new_grade) : name(name)
{

	if (new_grade < 1)
		throw GradeTooHighException();
	if (new_grade > 150)
		throw GradeTooLowException();
	this->grade = new_grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		(std::string) this->name = other.name;
		this->grade = other.grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& bur)
{
	os << bur.getName() << ", bureaucrat grade " << bur.getGrade();
	return os;
}

std::string Bureaucrat::getName()
{
	return this->name;
}
int Bureaucrat::getGrade()
{
	return this->grade;
}

void Bureaucrat::promoteBureaucrat()
{
	if (grade > 1)
		(this->grade)--;
	else
		throw GradeTooHighException();
}

void Bureaucrat::demoteBureaucrat()
{
	if (grade < 150)
		(this->grade)++;
	else
		throw GradeTooLowException();
}
