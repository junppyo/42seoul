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
		Fixed(const int);
		Fixed(const float);
		Fixed(const Fixed&);
		int getRawBits() const;
		void setRawBits(int const);
		~Fixed();
		Fixed & operator=(Fixed const &);
		float toFloat(void) const;
		int toInt(void) const;
		bool operator>(Fixed const &);
		bool operator<(Fixed const &);
		bool operator>=(Fixed const &);
		bool operator<=(Fixed const &);
		bool operator==(Fixed const &);
		bool operator!=(Fixed const &);
		Fixed & operator+(Fixed const &);
		Fixed & operator-(Fixed const &);
		Fixed & operator*(Fixed const &);
		Fixed & operator/(Fixed const &);
		Fixed & operator ++();
		Fixed & operator ++(int);
		Fixed & operator --();
		Fixed & operator --(int);
		static const Fixed & max(Fixed const &, Fixed const &);
};

std::ostream& operator<<(std::ostream& o, const Fixed& fixed);

#endif