#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("FragTrap")
{
	hit = 100;
	energy = 100;
	damage = 30;
	name = "FragTrap";
}

FragTrap::FragTrap(std::string input) : ClapTrap(input)
{
	hit = 100;
	energy = 100;
	damage = 30;
	name = input;
}

void FragTrap::highFivesGuys()
{
	std::cout << name << ": High Five!!" << std::endl;
} 