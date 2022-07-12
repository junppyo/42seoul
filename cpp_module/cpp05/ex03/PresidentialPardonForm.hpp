#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string&);
		PresidentialPardonForm(const PresidentialPardonForm&);
		~PresidentialPardonForm();
		int executee(Bureaucrat const&) const;
};

#endif