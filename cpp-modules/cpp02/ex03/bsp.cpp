#include "Point.hpp"
#include <cmath>

Fixed area(Point const a, Point const b, Point const c)
{
	float result = (a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) +
					b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()) +
					c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())) / 2.0f;

	return Fixed(fabsf(result));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed total = area(a, b, c);
	Fixed a1 = area(point, b, c);
	Fixed a2 = area(a, point, c);
	Fixed a3 = area(a, b, point);

	if (a1 == 0 || a2 == 0 || a3 == 0)
		return false;
	return (a1 + a2 + a3) == total;
}
