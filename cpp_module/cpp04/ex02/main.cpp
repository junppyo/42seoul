#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* i = new Dog();
	const Animal* j = new Cat();
	std::cout << i->getType() << std::endl;
	std::cout << j->getType() << std::endl;
	std::cout << "\n";
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	std::cout << "\n";

	delete i;
	delete j;
// meta->makeSound();
// 	const Animal* meta = new Animal();
// 	const Animal* j = new Cat();
// 	const Animal* i = new Dog();

// 	std::cout << j->getType() << std::endl;
// 	std::cout << i->getType() << std::endl;
// 	i->makeSound();
// 	j->makeSound();
// 	meta->makeSound();
// 	i->~Animal();
// 	meta->~Animal();
}