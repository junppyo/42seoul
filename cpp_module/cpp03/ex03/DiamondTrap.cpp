#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("DiamondTrap_clap_name")
{
	name = "DiamondTrap";
	max_hit = 100;
	hit = 100;
	max_energy = 50;
	damage = 30;
	std::cout << name << " is created" << std::endl;
}

DiamondTrap::DiamondTrap(std::string input) : ClapTrap(input + "_clap_name")
{
	name = input;
	max_hit = 100;
	hit = 100;
	max_energy = 50;
	damage = 30;
	std::cout << name << " is created" << std::endl;
}

void DiamondTrap::attack(std::string const& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "I'm " << name << " and clapname is " << ClapTrap::name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << name << " is destroyed" << std::endl;
}