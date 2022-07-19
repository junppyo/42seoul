#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	hit = 10;
	max_hit = 10;
	energy = 10;
	max_energy = 10;
	name = "NULL";
	damage = 0;
	std::cout << "Create Player " << name << std::endl;
}

ClapTrap::ClapTrap(const std::string &input)
{
	hit = 10;
	max_hit = 10;
	energy = 10;
	max_energy = 10;
	name = input;
	damage = 0;
	std::cout << "Create Player " << name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << name << " GAME OVER" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (!hit)
	{
		std::cout << "ClapTrap " << name << "'s HP is 0!!!!" << std::endl;
		return ;
	}
	if (!energy)
	{
		std::cout << "ClapTrap " << name << "'s ENERGY is 0!!!!" << std::endl;
		return ;
	}
	energy -= 1;
	std::cout << "ClapTrap " << name << " attacks " << target << " causing " << damage << " points of damage!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount) {
	hit -= amount;
	std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
	if (hit < 0)
		hit = 0;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (!hit)
	{
		std::cout << "ClapTrap " << name << "'s HP is 0!!!!" << std::endl;
		return ;
	}
	if (!energy)
	{
		std::cout << "ClapTrap " << name << "'s ENERGY is 0!!!!" << std::endl;
		return ;
	}
	energy -= 1;
	hit += amount;
	if (hit > max_hit)
		hit = max_hit;
	std::cout << "ClapTrap " << name << " is repair " << amount << " points."  << std::endl;
	std::cout << "ClapTrap " << name << "'s HP is " << hit << std::endl;
}

int ClapTrap::get_hp()
{
	return hit;
}