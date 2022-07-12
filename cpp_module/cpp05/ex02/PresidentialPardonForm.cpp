#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form(NULL, 25, 5)
{
	std::cout << "PresidentialPardonForm " << name << " is created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& _name) : Form(_name, 25, 5)
{
	std::cout << "PresidentialPardonForm " << name << " is created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& f) : Form(f.getName(), 25, 5)
{
	std::cout << "PresidentialPardonForm " << name << " is copied" << std::endl;
}
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm " << name << " is deleted" << std::endl;
}

int PresidentialPardonForm::executee(Bureaucrat const& b) const
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
		std::cout << "Informs that " << b.getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;	
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}