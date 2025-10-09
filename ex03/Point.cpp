#include "Point.hpp"

Point::Point(void) : x(0), y(0)
{
}

Point::Point(const float x, const float y) : x(x), y(y)
{
}

Point::Point(const Point &copy) : x(copy.getX()), y(copy.getY())
{
}

Point &Point::operator=(Point &other)
{
	return other;
}

Point::~Point(void)
{
}

const Fixed &Point::getX() const
{
	return x;
}

const Fixed &Point::getY() const
{
	return y;
}
