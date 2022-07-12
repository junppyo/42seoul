#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form(NULL, 72, 45)
{
	std::cout << "RobotomyRequestForm " << name << " is created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& _name) : Form(_name, 72, 45)
{
	std::cout << "RobotomyRequestForm " << name << " is created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& f) : Form(f.getName(), 72, 45)
{
	std::cout << "RobotomyRequestForm " << name << " is copied" << std::endl;
}
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm " << name << " is deleted" << std::endl;
}

int RobotomyRequestForm::executee(Bureaucrat const& b) const
{
	try
	{
		if (!getSigned())
		{
			throw NotSignedException();
		}
		if (b.getGrade() > execute)
		{
			throw GradeTooLowException();
		}
		srand((unsigned int)time(NULL));
		if (rand() % 2)
		{
			std::cout << b.getName() << " has been robotomized successfully." << std::endl;
		}
		else
		{
			std::cout << b.getName() << " informs that the robotomy failed." << std::endl;
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}