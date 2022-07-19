#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include "iostream"
#include <ctime>
#include <cstdlib>

class ClapTrap
{
	private:
		int hit;
		int max_hit;
		int energy;
		int max_energy;
		std::string name;
		int damage;
	public:
		ClapTrap();
		ClapTrap(const std::string&);
		~ClapTrap();
		void attack(const std::string&);
		void takeDamage(unsigned int);
		void beRepaired(unsigned int amount);
		int get_hp();
};

#endif