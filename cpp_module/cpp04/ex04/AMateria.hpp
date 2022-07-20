#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include "Character.hpp"

class AMateria
{
	protected:
		std::string type;
	public:
		AMateria(std::string const&);
		std::string const& getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif