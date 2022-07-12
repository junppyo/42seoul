#include "Zombie.hpp"

void randomChump(std::string input)
{
	Zombie z(input);
	z.announce();
}