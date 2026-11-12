
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class AForm;

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int new_grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		std::string getName() const;
		int getGrade() const;
		void promoteBureaucrat();
		void demoteBureaucrat();
		void signForm(AForm& f);
		void executeForm(AForm const & form) const;
};

std::ostream& operator<<(std::ostream& os, Bureaucrat& b);

#endif
