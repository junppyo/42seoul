#ifndef TEMPLATE_HPP
# define TEMPLATE_HPP

#include "iostream"

template <typename T>
void swap(T& a, T& b)
{
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}
template <typename T>
T min(T a, T b)
{
	return (a > b ? b : a);
}
template <typename T>
T max(T const& a, T const& b)
{
	return (a > b ? a : b);
}

#endif