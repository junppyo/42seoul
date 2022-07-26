#include "Cat.hpp"
#include "Dog.hpp"

void test_normal() {
	const Animal* i = new Cat();
	const Animal* j = new Dog();
	const Animal* k = new Dog();

	std::cout << std::endl;
	i->makeSound();
	j->makeSound();
	std::cout << std::endl;
	*(const_cast<Animal*>(k)) = *(const_cast<Animal*>(j));
	std::cout << std::endl;
	k->makeSound();
	std::cout << std::endl;

	delete k;
	delete j;
	delete i;
}

void test_array() {
	Animal* meta[10];

	for (int i = 0 ; i < 10 ; ++i) {
		if (!(i % 2)) {
			meta[i] = new Cat();
		} else {
			meta[i] = new Dog();
		}
	}
	for (int i = 0 ; i < 10 ; ++i)
		delete meta[i];
}

void test_brain()
{
	Brain *brain1 = new Brain();
	brain1->set_idea(0, "Walk?!");

	Brain *brain2 = new Brain(*brain1);

	Brain brain3;
	brain3 = *brain1;

	brain1->set_idea(0, "tired. . .");

	std::cout << *brain1 << std::endl;
	std::cout << *brain2 << std::endl;
	std::cout << brain3 << std::endl;

	delete brain1;
	delete brain2;
}

int main(void)
{
	std::cout << "\n==============test normal==============\n";
	test_normal();
	std::cout << "\n==============test array==============\n";
	test_array();
	std::cout << "\n==============test brain==============\n";
	test_brain();

	Cat a;
	Cat *b = new Cat(a);	
	std::cout << *(b->get_brain()) << std::endl;
	return 0;
}