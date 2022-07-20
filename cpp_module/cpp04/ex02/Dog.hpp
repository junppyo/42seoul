#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *brain;
	public:
		Dog();
		Dog(const Dog&);
		~Dog();
		void makeSound() const;
		const Brain *get_brain() const;
		Dog& operator=(const Dog&);
};

#endif