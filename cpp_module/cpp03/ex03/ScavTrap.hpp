#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const std::string&);
		void attack(const std::string&);
		virtual ~ScavTrap();
		void guardGate();
};

#endif