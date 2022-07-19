#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const std::string&);
		virtual ~FragTrap();
		void highFivesGuys();
		void attack(const std::string& target);
};

#endif