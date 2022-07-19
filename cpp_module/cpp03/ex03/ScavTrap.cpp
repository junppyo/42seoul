#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("ScavTrap")
{
	hit = 100;
	energy = 50;
	damage = 20;
	std::cout << name << " power on" << std::endl;
}

ScavTrap::ScavTrap(const std::string& input) : ClapTrap(input)
{
	hit = 100;
	energy = 50;
	damage = 20;
	std::cout << name << " power on" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << name << " power off" << std::endl;
}


void ScavTrap::attack(const std::string& target) {
	if (!hit)
	{
		std::cout << "ScavTrap " << name << "'s HP is 0!!!!" << std::endl;
		return ;
	}
	if (!energy)
	{
		std::cout << "ScavTrap " << name << "'s ENERGY is 0!!!!" << std::endl;
		return ;
	}
	energy -= 1;
	std::cout << "ScavTrap " << name << " attacks " << target << " causing " << damage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << name << " changes mode : Gate Keeper" << std::endl;
}