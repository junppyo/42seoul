#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string&);
		ShrubberyCreationForm(const ShrubberyCreationForm&);
		~ShrubberyCreationForm();
		int executee(Bureaucrat const&) const; 
};

#endif
