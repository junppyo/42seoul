#ifndef SPAN_HPP
#define SPAN_HPP

#include "iostream"
#include "exception"
#include "algorithm"

class Span
{
	private:
		int *data;
		const int size;
		int end;
	public:
		class FullException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "Array is already full";
				}
		};
		class NoSpanException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "No span can be found";
				}
		};
		Span();
		Span(unsigned int);
		~Span();
		void addNumber(int);
		int shortestSpan();
		int LongSpan();
};

#endif