#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		const Animal* meta = new Animal();
		const Animal* i = new Dog();
		const Animal* j = new Cat();
		std::cout << i->getType() << " " << std::endl;
		std::cout << j->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		std::cout << i->getType() << std::endl;
		std::cout << j->getType() << std::endl;
		std::cout << meta->getType() << std::endl;
	}
	std::cout << "\n";
	{
		const WrongAnimal* w = new WrongCat();
		w->makeSound();
	}
}