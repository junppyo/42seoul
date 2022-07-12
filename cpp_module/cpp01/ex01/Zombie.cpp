#include "Zombie.hpp"

Zombie::Zombie()
{
	this->name = "";
}

Zombie::Zombie(std::string input)
{
	this->name = input;
}

void Zombie::announce()
{
	std::cout << this->name << " BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName(std::string input)
{
	this->name = input;
}

Zombie::~Zombie()
{
	std::cout << this->name << " dead\n";
}
