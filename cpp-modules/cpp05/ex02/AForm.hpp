
#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <stdbool.h>

class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		bool isSigned;
		int gradeToSign;
		int gradeToExec;
	public:
		AForm();
		AForm(const std::string& name, int newGradeToSign, int newGradeToExec);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		std::string getName() const;
		int getGradeToSign() const;
		int getGradeToExec() const;
		bool getIsSigned() const;
		void beSigned(Bureaucrat& bur);
		virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, AForm& f);

#endif
