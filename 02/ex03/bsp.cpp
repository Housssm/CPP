#include <cmath>
#include <iostream>
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed d1 = (b.getx() - a.getx()) * (point.gety() - a.gety()) - (b.gety() - a.gety()) * (point.getx() - a.getx()); // AB ->AP
	Fixed d2 = (c.getx() - b.getx()) * (point.gety() - b.gety()) - (c.gety() - b.gety()) * (point.getx() - b.getx()); // BC ->BP
	Fixed d3 = (a.getx() - c.getx()) * (point.gety() - c.gety()) - (a.gety() - c.gety()) * (point.getx() - c.getx()); // CA ->CP

	if ((d1 > 0 && d2 > 0 && d3 > 0) || (d1 <0 && d2 < 0 && d3 < 0))
		return true;
	else
		return false;
}
