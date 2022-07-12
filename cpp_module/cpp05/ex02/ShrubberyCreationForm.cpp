#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form(NULL, 145, 137)
{
	std::cout << "ShrubberyCreationForm " << name << " is created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& _name) : Form(_name, 145, 137)
{
	std::cout << "ShrubberyCreationForm " << name << " is created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &f) : Form(f.getName(), 145, 137)
{
	std::cout << "ShrubberyCreationForm " << name << " is copied" << std::endl;
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm " << name << " is deleted" << std::endl;
}

int ShrubberyCreationForm::executee(Bureaucrat const& b) const
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
	//	std::string file_name = b + "_shrubbery";
	//	FILE *f = fopen(file_name, "w");
	//	fclose(f);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}