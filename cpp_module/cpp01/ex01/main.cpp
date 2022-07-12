#include "Zombie.hpp"

int main()
{
	Zombie *zombies;

	zombies = zombieHorde(5, "zzzz");

	for(int i = 0; i < 5;i++)
	{
		zombies[i].announce();
	}
	delete[] zombies;
}