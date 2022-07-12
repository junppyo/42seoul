#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include "iostream"

class Zombie
{
	private:
		std::string name;
	public:
		void announce();
		Zombie();
		Zombie(std::string);
		~Zombie();
};

Zombie* newZombie(std::string);
void randomChump(std::string);
#endif