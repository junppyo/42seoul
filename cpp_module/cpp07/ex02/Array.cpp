#include "Array.hpp"

// template <typename T>
// Array<T>::Array() : value(0), size_(0)
// {
// }

// template <typename T>
// Array<T>::Array(unsigned int n) : value(NULL), size_(n)
// {
// 	if (size_)
// 		value = new T[n];
// }

// template <typename T>
// Array<T>::Array(const Array<T> &a)

// template <typename T>
// int Array<T>::size() const
// {
// 	return size;
// }

// template <typename T>
// T& Array<T>::operator[](int idx)
// {
// 	try
// 	{
// 		if (idx < 0 || idx >= size_)
// 			throw Array<T>::OutofRange();
// 		return value[idx];
// 	}
// 	catch (std::exception& e)
// 	{
// 		std::cout << e.what() << std::endl;
// 	}
// 	return (0);
// }

// template <typename T>
// Array<T>::~Array()
// {
// 	if (size_)
// 		delete[] value;
// }
