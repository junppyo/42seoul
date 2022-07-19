#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include "iostream"
#include <ctime>
#include <cstdlib>

class ClapTrap
{
	protected:
		int hit;
		int max_hit;
		int energy;
		int max_energy;
		std::string name;
		int damage;
	public:
		ClapTrap();
		ClapTrap(const std::string&);
		virtual ~ClapTrap();
		virtual void attack(std::string const&);
		void takeDamage(unsigned int);
		void beRepaired(unsigned int amount);
		int get_hp();
};

#endif