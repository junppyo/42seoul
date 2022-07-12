#include "Zombie.hpp"

Zombie* newZombie(std::string input)
{
	Zombie *z = new Zombie(input);
	return z;
}