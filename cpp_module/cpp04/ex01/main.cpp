#include "Cat.hpp"
#include "Dog.hpp"

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

void test_copy()
{
	Cat a;
	(const_cast<Brain *>(a.get_brain()))->set_idea(0, "asdf");
	
	Cat b = a;
	std::cout << *(b.get_brain()) << std::endl;
}

int main(void)
{
	std::cout << "\n==============test array==============\n";
	test_array();
	std::cout << "\n==============test brain==============\n";
	test_brain();
	std::cout << "\n==============test copy==============\n";
	test_copy();

	return 0;
}