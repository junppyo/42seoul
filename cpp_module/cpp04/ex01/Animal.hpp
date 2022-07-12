#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include "iostream"
#include "Brain.hpp"
class Animal
{
	public:
		Animal();
		virtual ~Animal();
		virtual std::string getType() const;
		virtual void makeSound() const;
};


#endif