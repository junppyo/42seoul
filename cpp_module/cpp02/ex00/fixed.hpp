#ifndef FIXED_HPP
# define FIXED_HPP

#include "iostream"

class Fixed
{
	private:
		int value;
		static const int bit = 8;

	public:
		Fixed();
		Fixed(int);
		Fixed(float);
		Fixed(const Fixed&);
		int getRawBits() const;
		void setRawBits(int const);
		~Fixed();
		Fixed & operator=(Fixed const &);
};

#endif