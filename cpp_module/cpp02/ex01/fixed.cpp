#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	value = 0;
}

Fixed::Fixed(const float src)
{
	std::cout << "Float constructor called" << std::endl;
	value = roundf(src * 256);
}

Fixed::Fixed(const int src)
{
	std::cout << "Int constructor called" << std::endl;
	value = src * 256;
}

Fixed::Fixed(const Fixed& src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

void Fixed::setRawBits(int const input)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->value = input;
}

Fixed & Fixed::operator=(Fixed const &src)
{
	std::cout << "Assignation operator called" << std::endl;
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

std::ostream& operator<<(std::ostream& o, const Fixed& fixed)
{
	return o << fixed.toFloat();
}