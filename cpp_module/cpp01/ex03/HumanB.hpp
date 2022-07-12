#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string);
		HumanB(std::string, Weapon&);
		void attack();
		void setWeapon(Weapon&);
		~HumanB();
	private:
		std::string _name;
		Weapon *_weapon;
};

#endif