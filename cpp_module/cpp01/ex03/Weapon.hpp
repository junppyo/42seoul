#ifndef WEAPON_HPP
# define WEAPON_HPP

# include "iostream"

class Weapon
{
	private:
		std::string type;
	public:
		Weapon(const std::string&);
		const std::string& getType();
		void setType(std::string);
		~Weapon();
};

#endif