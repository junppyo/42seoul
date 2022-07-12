#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

void ExecuteTest()
{
	Form *form1 = new PresidentialPardonForm("form1");
	Bureaucrat bureaucrat1("1", 5);
	Bureaucrat bureaucrat2("2", 120);

	bureaucrat2.signForm(*form1);
	bureaucrat1.signForm(*form1);
	bureaucrat2.executeForm(*form1);
	bureaucrat1.executeForm(*form1);

	delete form1;
}

void InternTest()
{
	Intern *intern = new Intern();
	Form *internform = intern->makeForm("presidential pardon", "AA");
	std::cout << *internform << std::endl;

	delete intern;
	delete internform;
}

int main()
{
	ExecuteTest();
	std::cout << "\n=================================\n" << std::endl;
	InternTest();
}