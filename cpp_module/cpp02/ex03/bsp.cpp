#include "Point.hpp"


bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	int 	cross_count = 0;
	Fixed	check_x;
	
	if ((a.getY() > point.getY()) != (b.getY() > point.getY()))
	{
		check_x = (b.getX() - a.getX()) * (point.getY() - a.getY()) / (b.getY() - a.getY()) + a.getX();
		if (point.getX() < check_x)
			cross_count++;
	}


	if ((b.getY() > point.getY()) != (c.getY() > point.getY()))
	{
		check_x = (c.getX() - b.getX()) * (point.getY() - b.getY()) / (c.getY() - b.getY()) + b.getX();
		if (point.getX() < check_x)
			cross_count++;
	}

	if ((c.getY() > point.getY()) != (a.getY() > point.getY()))
	{
		check_x = (a.getX() - c.getX()) * (point.getY() - c.getY()) / (a.getY() - c.getY()) + c.getX();
		if (point.getX() < check_x)
			cross_count++;
	}
	
	return (cross_count % 2 == 1);
}
