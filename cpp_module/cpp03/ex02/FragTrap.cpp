#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("FragTrap")
{
	hit = 100;
	energy = 100;
	damage = 30;
	std::cout << name << " login" << std::endl;
}

FragTrap::FragTrap(const std::string& input) : ClapTrap(input)
{
	hit = 100;
	energy = 100;
	damage = 30;
	std::cout << name << " login" << std::endl;
}

void FragTrap::attack(const std::string& target) {
	if (!hit)
	{
		std::cout << "FragTrap " << name << "'s HP is 0!!!!" << std::endl;
		return ;
	}
	if (!energy)
	{
		std::cout << "FragTrap " << name << "'s ENERGY is 0!!!!" << std::endl;
		return ;
	}
	energy -= 1;
	std::cout << "FragTrap " << name << " attacks " << target << " causing " << damage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::string in;
	std::cin >> in;
	std::cout << name << ": Hey, " << in << "! High Five!!" << std::endl;
} 

FragTrap::~FragTrap()
{
	std::cout << name << " logout" << std::endl;
}