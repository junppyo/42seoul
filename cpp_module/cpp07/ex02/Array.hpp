#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "iostream"
#include "exception"

template <typename T>
class Array
{
	private:
		T *value;
		int size_;
	public:
		class OutofRange : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return "except";
				}
		};
		Array() : value(NULL), size_(0){
		}
		Array(unsigned int n) : value(NULL), size_(n) {
			if (size_)
				value = new T[size_];
		}
		Array(const Array &a)  : value(NULL), size_(a.size())
		{
			if (size_)
				value = new T[size_];
			for (int i = 0; i < size_; i++)
			{
				value[i] = a[i];
			}
		}
		int size() const
		{
			return size_;
		}
		T& operator[](int idx)
		{
			try
			{
				if (idx < 0 || idx >= size_)
					throw Array<T>::OutofRange();
				return value[idx];
			}
			catch (std::exception& e)
			{
				std::cout << e.what() << std::endl;
				return value[0];
			}
		}
		const T& operator[](int idx) const
		{
			try
			{
				if (idx < 0 || idx >= size_)
					throw Array<T>::OutofRange();
				return value[idx];
			}
			catch (std::exception& e)
			{
				std::cout << e.what() << std::endl;
				return value[0];
			}
		}
		~Array()
		{
			if (size_)
				delete[] value;
		}
		Array& operator=(const Array& a) {
			if (this == &a)
				return *this;
			if (size_)
			{
				delete[] value;
				value = NULL;
			}
			size_ = a.size();
			if (size_)
			{
				value = new T[size_];
				for (int i = 0 ; i < size_; i++)
					value[i] = a[i];
			}
		}
};

#endif