#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include "iostream"
#include "vector"
#include "exception"

class NotFoundException : public std::exception
{
	public:
		const char* what() const throw(){
			return "Not Found";
		}
};

template <typename T>
typename T::iterator easyfind(T* a, int b)
{
	typename T::iterator iter;
	iter = std::find(std::begin(*a), std::end(*a), b);
	if (iter == std::end(*a))
		throw NotFoundException();
	return iter;
}

#endif