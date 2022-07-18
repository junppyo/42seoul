#include "template.hpp"

int main()
{
	int a1, b1;
	float a2, b2;

	a1 = 10; b1 = 20;
	a2 = 30; b2 = 10;
	swap(a1, b1);
	swap(a2, b2);
	std::cout << "swap 	a1: " << a1 << " b1: " << b1 << std::endl;
	std::cout << "swap 	a2: " << a2 << " b2: " << b2 << std::endl;
 	std::cout << "\na1,b1 min: " << min(a1, b1) << std::endl;
 	std::cout << "a2,b2 min: " << min(a2, b2) << std::endl;
 	std::cout << "\na1,b1 max: " << max(a1, b1) << std::endl;
 	std::cout << "a2,b2 max: " << max(a2, b2) << std::endl;
 }