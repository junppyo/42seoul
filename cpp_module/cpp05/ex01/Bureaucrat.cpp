#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("NULL"), grade(15)
{
	std::cout << "hire Burecrat someone" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& _name, const int& n) : name(_name)
{
	if (n <= 0)
		throw GradeTooHighException();
	else if (n > 150)
		throw GradeTooLowException();
	this->grade = n;
	std::cout << "hire Burecrate " << name << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& b) : name(b.getName())
{
	grade = b.getGrade();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& b)
{
	if (&b != this)
		*(const_cast<std::string*>(&name)) = b.getName();
		grade = b.getGrade();
	return *this;
}

void Bureaucrat::signForm(const Form& form) const
{
	try
	{
		(*const_cast<Form*>(&form)).beSigned(*this);
		if (!form.getSigned())
			throw std::exception();
		std::cout << name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << name << " couldn't sign " << form.getName() << " because grade too low" << std::endl;
	}
}

Bureaucrat::~Bureaucrat()
{
	std::cout << name << " is fired" << std::endl;
}

std::string Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

void Bureaucrat::setIncreaseGrade(int n)
{
	try
	{
		if (grade - n <= 0)
			throw GradeTooHighException();
		else if (grade - n > 150)
			throw GradeTooLowException();
		grade -= n;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void Bureaucrat::setDecreaseGrade(int n)
{
	try
	{
		if (grade + n <= 0)
			throw GradeTooHighException();
		else if (grade + n > 150)
			throw GradeTooLowException();
		grade += n;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& b)
{
	std::cout << b.getName() << ", bureaucrat grade " << b.getGrade();
	return o;
}