
#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <string>
#include <iostream>
#include <exception>

class GradeTooHighException : public std::exception
{
	public:
		const char* what() const throw();
};

class GradeTooLowException : public std::exception
{
	public:
		const char* what() const throw();
};

class FormNotSignedException: public std::exception
{
	public:
		const char* what() const throw();
};

#endif
