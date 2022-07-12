#include "Weapon.hpp"

Weapon::Weapon(std::string weapon)
{
	this->type = weapon;
}

std::string Weapon::getType()
{
	return (type);
}

void Weapon::setType(std::string input)
{
	this->type = input;
}

Weapon::~Weapon()
{
}