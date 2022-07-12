#ifndef INTERN_HPP
# define INTERN_HPP

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Form* makeForm(const char *type, const char *name);
		Intern();
		~Intern();
};

#endif