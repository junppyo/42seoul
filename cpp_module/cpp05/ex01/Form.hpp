#ifndef FORM_HPP
# define FORM_HPP

#include "iostream"
#include "exception"
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string name;
		bool sign;
		const int require;
		const int execute;	public:
		Form();
		Form(const std::string&, const int&, const int&);
		Form(const Form&);
		Form& operator=(const Form&);
		~Form();
		void beSigned(const Bureaucrat&);
		std::string getName() const;
		int getRequire() const;
		int getExecute() const;
		bool getSigned() const;
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
};

std::ostream& operator<<(std::ostream&, Form&);

#endif