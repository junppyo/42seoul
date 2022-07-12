#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Form* Intern::makeForm(const char *type, const char *name)
{
	int n = -1;
	std::string forms_type[3] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};
	for (int i = 0 ; i < 3; i++)
	{
		if (type == forms_type[i])
			n = i;
	}
	switch (n)
	{
		case 0:
			std::cout << "Intern creates " << name << std::endl;
			return (new PresidentialPardonForm(name));
			break ;
		case 1:
			std::cout << "Intern creates " << name << std::endl;
			return (new RobotomyRequestForm(name));
			break ;
		case 2:
			std::cout << "Intern creates " << name << std::endl;
			return (new ShrubberyCreationForm(name));
			break ;
	}
	std::cout << "Intern couldn't creates " << name << std::endl;
	return NULL;
}