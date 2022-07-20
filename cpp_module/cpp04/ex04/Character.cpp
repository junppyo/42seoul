#include "Character.hpp"

Character::Character(const std::string& input)
{
	name = input;
	idx = 0;
	std::cout << name << " is created" << std::endl;
}

std::string const &getName() const
{
	return name;
}

void Character::equip(AMateria* m)
{
	if (idx < 5)
	{
		inventory[idx] = m;
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
	idx--;
	if (idx != n)
	{
		int i = n;
		while (i <= idx)
		{
			inventory[i] = inventory[i + 1];
			i++;
		}
	}
}

void Character::showStatus() const
{
	std::cout << "name: " << name << std::endl;
	std::cout << "inventory" << std::endl;
	if (idx == 0)
		std::cout << "empty" << std::endl;
	else
	{
		for (int i = 0; i < idx; i++)
		{
			std::cout << i << ": " << inventory[i]->getType() << std::endl;
		}
	}
}