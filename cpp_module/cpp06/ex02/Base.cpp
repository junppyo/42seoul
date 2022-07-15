#include "Base.hpp"
#include "ctime"
#include "cstdlib"

Base *generate()
{
	srand(time(NULL));
	int n = rand() % 3;
	switch(n)
	{
		case 0:
			std::cout << "create A" << std::endl;
			return (new A);
		case 1:
			std::cout << "create B" << std::endl;
			return (new B);
		case 2:
			std::cout << "create C" << std::endl;
			return (new C);
	}
	return (0);
}
void identify(Base* b)
{
	if (dynamic_cast<A*>(b))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(b))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(b))
		std::cout << "C" << std::endl;
}

int cast(Base& b, std::string s)
{
	try
	{
		if (s == "A")
			(void)dynamic_cast<A&>(b);
		if (s == "B")
			(void)dynamic_cast<B&>(b);
		if (s == "C")
			(void)dynamic_cast<C&>(b);
		std::cout << s << std::endl;
	}
	catch (std::exception& e)
	{
		return (1);
	}
	return (0);
}

void identify(Base& b)
{
	if (cast(b, "A"))
	{
		if (cast(b, "B"))
		{
			if (cast(b, "C"))
			{
				std::cout << "error" << std::endl;
			}
		}
	}
}