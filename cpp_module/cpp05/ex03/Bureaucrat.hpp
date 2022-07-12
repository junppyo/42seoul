#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include "iostream"
#include "exception"
//#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string&, const int&);
		Bureaucrat(const Bureaucrat&);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat&);
		std::string getName() const;
		int getGrade() const;
		void setIncreaseGrade(int);
		void setDecreaseGrade(int);
		void signForm(const Form&) const;
		class GradeTooHighException : public std::exception {
			public:
				const char* what(void) const throw()
				{
					return "Exception: Grade Too High!";
				}
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what(void) const throw()
				{
					return "Exception: Grade Too Low!";
				}
		};
		void executeForm(Form const&);

};

std::ostream& operator<<(std::ostream&, const Bureaucrat&);
#endif