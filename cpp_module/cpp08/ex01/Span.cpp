#include "Span.hpp"

Span::Span() : size(0)
{
	data = NULL;
	end = 0;
}

Span::Span(unsigned int n) : size(n)
{
	data = new int[n];
	end = 0;
}

void Span::addNumber(int n)
{
	if (end == size)
		throw FullException();
	data[end] = n;
	end++;
}

int Span::shortestSpan()
{
	if (end <= 1)
		throw NoSpanException();
	int min = 2147483647;
	std::sort(data, data + end);
	for (int i = 0 ; i < end - 1; i++)
	{
		if (data[i + 1] - data[i] < min)
			min = data[i + 1] - data[i];
	}
	return (min);
}

int Span::LongSpan()
{
	if (end <= 1)
		throw NoSpanException();
	
	std::sort(data, data + end);
	return (data[end - 1] - data[0]);
}

Span::~Span()
{
	if (size)
		delete[] data;
}