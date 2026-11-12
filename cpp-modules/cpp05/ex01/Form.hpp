
#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <stdbool.h>

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool isSigned;
		int gradeToSign;
		int gradeToExec;
	public:
		Form();
		Form(const std::string& name, int newGradeToSign, int newGradeToExec);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		std::string getName() const;
		int getGradeToSign() const;
		int getGradeToExec() const;
		bool getIsSigned() const;
		void beSigned(Bureaucrat& bur);
};

std::ostream& operator<<(std::ostream& os, Form& f);

#endif




