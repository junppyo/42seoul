#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include "ctime"
#include "cstdlib"

class RobotomyRequestForm : public Form
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string&);
		RobotomyRequestForm(const RobotomyRequestForm&);
		~RobotomyRequestForm();
		int executee(Bureaucrat const&) const;
};

#endif