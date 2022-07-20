#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "iostream"
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string name;
		AMateria *inventory[5];
		int idx;
	public:
		Character(const std::string&);
		virtual ~Character() {}
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int n);
		void use(int n, ICharacter& target);
		void showStatus() const;
};

#endif