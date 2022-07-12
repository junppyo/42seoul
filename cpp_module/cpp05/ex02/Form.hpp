#ifndef FORM_HPP
# define FORM_HPP

#include "iostream"
#include "exception"
#include "Bureaucrat.hpp"

class Form
{
	protected:
		const std::string name;
		bool sign;
		const int require;
		const int execute;
	public:
		Form();
		Form(const std::string&, const int&, const int&);
		Form(const Form&);
		virtual Form& operator=(const Form&);
		virtual ~Form();
		int beSigned(const Bureaucrat&);
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
		class NotSignedException : public std::exception {
			public:
				const char* what(void) const throw()
				{
					return "Exception: This from is not signed!";
				}
		};
		virtual int executee(Bureaucrat const&) const = 0;
};

std::ostream& operator<<(std::ostream&, Form&);

#endif