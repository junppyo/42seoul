#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("ScavTrap")
{
	hit = 100;
	energy = 50;
	damage = 20;
	name = "ScavTrap";
	std::cout << name << " power on" << std::endl;
}

ScavTrap::ScavTrap(std::string input) : ClapTrap(input)
{
	hit = 100;
	energy = 50;
	damage = 20;
	name = input;
	std::cout << name << " power on" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << name << " power off" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << name << " changes mode : Gate Keeper" << std::endl;
}