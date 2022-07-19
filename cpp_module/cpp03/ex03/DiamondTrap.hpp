#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string name;
	public:
		DiamondTrap();
		DiamondTrap(std::string);
		virtual ~DiamondTrap();
//		using ClapTrap::name;
		// using FragTrap::max_hit;
		// using ScavTrap::max_energy;
		// using FragTrap::damage;
		void attack(std::string const&);
		void whoAmI();
};

#endif