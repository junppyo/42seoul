#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
}

HumanB::HumanB(std::string name, Weapon &weapon) : _name(name), _weapon(&weapon)
{
}

void HumanB::attack()
{
	std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

HumanB::~HumanB()
{
}