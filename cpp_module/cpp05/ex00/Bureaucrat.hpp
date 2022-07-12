#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include "iostream"
#include "exception"

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string&, const int&);
		~Bureaucrat();
		std::string getName() const;
		int getGrade() const;
		void setIncreaseGrade(int);
		void setDecreaseGrade(int);
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

std::ostream& operator<<(std::ostream&, const Bureaucrat&);
#endif