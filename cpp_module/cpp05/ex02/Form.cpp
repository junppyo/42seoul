#include "Form.hpp"

Form::Form() : name("NULL"), sign(0), require(150), execute(150)
{
	std::cout << name << " Form is created" << std::endl;
}

Form::Form(const std::string& _name, const int& _require, const int& _execute) : name(_name), require(_require), execute(_execute)
{
	try
	{
		if (_require <= 0 || _execute <= 0)
			throw GradeTooHighException();
		if (_require > 150 || _execute > 150)
			throw GradeTooLowException();
		std::cout << name << " is created" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

Form::Form(const Form& f) : name(f.getName()), require(f.getRequire()), execute(f.getExecute())
{
	if (require <= 0 || execute <= 0)
		throw GradeTooHighException();
	if (require > 150 || execute > 150)
		throw GradeTooLowException();
}

Form& Form::operator=(const Form& f)
{
	if (&f != this)
	{
		*(const_cast<std::string*>(&name)) = f.getName();
		*(const_cast<int*>(&require)) = f.getRequire();
		*(const_cast<int*>(&execute)) = f.getExecute();
		sign = f.getSigned();
	}
	return *this;
}

int Form::beSigned(const Bureaucrat& b)
{
	try
	{
		if (require < b.getGrade())
			throw GradeTooLowException();
		sign = true;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}

std::string Form::getName() const
{
	return name;
}

bool Form::getSigned() const
{
	return sign;
}

int Form::getRequire() const
{
	return require;
}

int Form::getExecute() const
{
	return execute;
}

Form::~Form()
{
	std::cout << "delete " << name << std::endl;
}

std::ostream& operator<<(std::ostream& o, Form& f)
{
	if (f.getSigned())
		std::cout << f.getName() << " is signed";
	else
		std::cout << f.getName() << " is unsigned";
	return o;
}