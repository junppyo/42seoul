#include "Character.hpp"

Character::Character(const std::string& input)
{
	name = input;
	idx = 0;
	std::cout << name << " is created" << std::endl;
}

Character::~Character()
{

}

std::string const& Character::getName() const
{
	return name;
}

void Character::equip(AMateria* m)
{
	if (idx < 4)
	{
		bag[idx] = m;
		idx++;
	}
	else
	{
		std::cout << "can't equip more!" << std::endl;
	}
}

void Character::unequip(int n)
{
	if (idx < n)
	{
		std::cout << "Invalid Item" << std::endl;
		return ;
	}
	bag[n] = NULL;
	idx--;
	if (idx != n)
	{
		int i = n;
		while (i < idx) 
		{
			bag[i] = bag[i + 1];
			i++;
		}
	}
}

void Character::use(int n, ICharacter& target)
{
	if (idx <= n)
		return ;
	bag[n]->use(target);
}

void Character::showStatus() const
{
	std::cout << "name: " << name << std::endl;
	std::cout << "bag" << std::endl;
	if (idx == 0)
		std::cout << "empty" << std::endl;
	else
	{
		for (int i = 0; i < idx; i++)
		{
			std::cout << i << ": " << bag[i]->getType() << std::endl;
		}
	}
}

AMateria* Character::getBag(int n) const
{
	if (idx <= n)
		return 0;
	return bag[n];
}

Character& Character::operator=(const Character& input)
{
	if (this == &input)
		return *this;
	name = input.getName();
	int i = 0;
	while (i < 4 && input.getBag(i))
	{
		bag[i] = (input.getBag(i))->clone();
		i++;
	}
	return *this;
}