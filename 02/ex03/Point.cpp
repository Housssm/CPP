#include "Point.hpp"
#include <cmath>

Point::Point(): _x(0), _y(0)
{
}

Point::Point(const float x_value, const float y_value): _x(x_value), _y(y_value)
{
}

Point::Point(const Point& other): _x(other._x), _y(other._y)
{
}

Point& Point::operator=(const Point& other)
{
	if (this != &other)
	{
	}
	return *this;
}

Point::~Point()
{
}

Fixed	Point::getx() const
{
	return this->_x;
}

Fixed	Point::gety() const
{
	return this->_y;
}
