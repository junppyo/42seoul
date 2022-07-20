#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "iostream"
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string name;
		AMateria *bag[4];
		int idx;
	public:
		Character(const std::string&);
		~Character();
		std::string const & getName() const;
		void equip(AMateria*);
		void unequip(int);
		void use(int, ICharacter&);
		void showStatus() const;
		AMateria *getBag(int) const;
		Character& operator=(const Character&);
};

#endif