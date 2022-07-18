#include "Span.hpp"
#include "cstdlib"
#include "ctime"

int main()
{
	{
		Span s(10);
		try
		{
			std::cout << "LongSpan: " << s.LongSpan() << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		s.addNumber(10);
		try
		{
			std::cout << "LongSpan: " << s.LongSpan() << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\n";
	{
		Span s(5);
		s.addNumber(6);
		s.addNumber(3);
		s.addNumber(17);
		s.addNumber(9);
		s.addNumber(11);
		std::cout << "shrotestSpan: " << s.shortestSpan() << std::endl;
		std::cout << "LongSpan: " << s.LongSpan() << std::endl;
	}
	std::cout << "\n";
	{
		srand(time(NULL));
		Span s(10000);
		
		for (int i = 0; i < 10000;i++)
		{
			s.addNumber(rand() % 1000000);
		}
		std::cout << "shrotestSpan: " << s.shortestSpan() << std::endl;
		std::cout << "LongSpan: " << s.LongSpan() << std::endl;
		try
		{
			s.addNumber(10);
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}