#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string, Weapon&);
		void attack();
		~HumanA();
	private:
		std::string _name;
		Weapon &_weapon;
};

#endif