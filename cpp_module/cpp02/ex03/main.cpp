#include "Point.hpp"


int main()
{
	Point a(0, 0);
	Point b(20, 0);
	Point c(10, 30);
	Point in(10, 15);
	Point out(30, 50);

	std::cout << "in: " << bsp(a, b, c, in) << std::endl;
	std::cout << "out: " << bsp(a, b, c, out) << std::endl;
}