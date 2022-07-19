#include "Fixed.hpp"

Fixed::Fixed()
{
	value = 0;
}

Fixed::Fixed(const float src)
{
	value = roundf(src * 256);
}

Fixed::Fixed(const int src)
{
	value = src * 256;
}

Fixed::Fixed(const Fixed& src)
{
	*this = src;
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits() const
{
	return this->value;
}

void Fixed::setRawBits(int const input)
{
	this->value = input;
}

Fixed & Fixed::operator=(Fixed const &src)
{
	this->value = src.getRawBits();
	return (*this);
}

float Fixed::toFloat(void) const
{
	return (float)this->value / (float) 256;
}

int Fixed::toInt(void) const
{
	return this->value / 256;
}

bool Fixed::operator>(Fixed const &input)
{
	if (value > input.getRawBits())
		return (1);
	return (0);
}
bool Fixed::operator<(Fixed const &input)
{
	if (value < input.getRawBits())
		return (1);
	return (0);
}
bool Fixed::operator>=(Fixed const &input)
{
	if (value >= input.getRawBits())
		return (1);
	return (0);
}
bool Fixed::operator<=(Fixed const &input)
{
	if (value <= input.getRawBits())
		return (1);
	return (0);
}
bool Fixed::operator==(Fixed const &input)
{
	if (value == input.getRawBits())
		return (1);
	return (0);
}
bool Fixed::operator!=(Fixed const &input)
{
	if (value != input.getRawBits())
		return (1);
	return (0);
}

Fixed & Fixed::operator+(Fixed const &input)
{
	Fixed *ret = new Fixed(toFloat() + input.toFloat());
	return *ret;
}
Fixed & Fixed::operator-(Fixed const &input)
{
	Fixed *ret = new Fixed(toFloat() - input.toFloat());
	return *ret;
}
Fixed & Fixed::operator*(Fixed const &input)
{
	Fixed *ret = new Fixed(toFloat() * input.toFloat());
	return *ret;
}
Fixed & Fixed::operator/(Fixed const &input)
{
	Fixed *ret = new Fixed(toFloat() / input.toFloat());
	return *ret;
}
Fixed & Fixed::operator ++ ()
{
	value++;
	return *this;
}

Fixed & Fixed::operator ++ (int)
{
	Fixed *ret = new Fixed(*this);
	value++;
	return *ret;
}
Fixed & Fixed::operator -- ()
{
	value--;
	return *this;
}
Fixed & Fixed::operator -- (int)
{
	Fixed *ret = new Fixed(*this);
	value--;
	return *ret;
}
const Fixed & Fixed::max(Fixed const &input1, Fixed const &input2)
{
	if (input1.toFloat() >= input2.toFloat())
		return input1;
	else
		return input2;
}
std::ostream& operator<<(std::ostream& o, const Fixed& fixed)
{
	return o << fixed.toFloat();
}


bool operator>(Fixed const &input1, Fixed const &input2)
{
	if (input1.getRawBits() > input2.getRawBits())
		return (1);
	return (0);
}

bool operator<(Fixed const &input1, Fixed const &input2)
{
	if (input1.getRawBits() < input2.getRawBits())
		return (1);
	return (0);
}

Fixed & operator+(Fixed const &input1, Fixed const &input2)
{
	Fixed *ret = new Fixed(input1.toFloat() * input2.toFloat());
	return *ret;
}
Fixed & operator-(Fixed const &input1, Fixed const &input2)
{
	Fixed *ret = new Fixed(input1.toFloat() - input2.toFloat());
	return *ret;
}
Fixed & operator*(Fixed const &input1, Fixed const &input2)
{
	Fixed *ret = new Fixed(input1.toFloat() * input2.toFloat());
	return *ret;
}
Fixed & operator/(Fixed const &input1, Fixed const &input2)
{
	Fixed *ret = new Fixed(input1.toFloat() / input2.toFloat());
	return *ret;
}