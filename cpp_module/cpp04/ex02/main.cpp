#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* i = new Dog();
	const Animal* j = new Cat();
	std::cout << i->getType() << std::endl;
	std::cout << j->getType() << std::endl;
	std::cout << "\n";
	i->makeSound(); //will output the Dog sound!
	j->makeSound();
	std::cout << "\n";

	delete i;
	delete j;
}