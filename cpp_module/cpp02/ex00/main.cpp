#include <iostream>
#include "fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	c.setRawBits(0);
	std::cout << c.getRawBits() << std::endl;
	return 0;
}