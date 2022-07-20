#include "Weapon.hpp"

Weapon::Weapon(const std::string& weapon)
{
	this->type = weapon;
}

const std::string& Weapon::getType()
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