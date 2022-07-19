#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(const float _x, const float _y) : x(_x), y(_y)
{
}

Point::~Point()
{
}

Point::Point(const Point &input) : x(input.getX()), y(input.getY())
{

}

Point & Point::operator=(const Point &input)
{
	if (this == &input)
		return *this;
	Point *ret = new Point(input.getX().toFloat(), input.getY().toFloat());
	return *ret;
}

const Fixed & Point::getX() const
{
	return x;
}
const Fixed & Point::getY() const
{
	return y;
}