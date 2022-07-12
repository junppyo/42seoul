#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ScavTrap
{
	public:
		FragTrap();
		FragTrap(std::string);
		~FragTrap();
		void highFivesGuys();
}