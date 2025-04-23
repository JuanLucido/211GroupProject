#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#include "lineType.h"

//sets line
void lineType::setLine(double x, double y)
{
	x1 = x;
	y1 = y;
	m1 = y1 / x1;
	b1 = y1 - m1 * x1;
}
//gets x coord
double lineType::getx1()
{
	return x1;
}
//gets y coord
double lineType::gety1()
{
	return y1;
}
//gets slope
double lineType::getm1()
{
	return m1;
}
//checks if lines are equal
bool lineType::equalToEachOther(lineType& obj)
{
	return (x1 == obj.x1 && y1 == obj.y1);
}
//checks if lines are perpendicular
bool lineType::isPerpendicular(lineType& obj)
{
	return ((m1 * obj.m1) == -1);
}
//checks if lines are parallel
bool lineType::isParallel(lineType& obj)
{
	return (m1 == obj.m1);
}
//intersection functions
bool lineType::intersectionPoints(lineType& obj, double& x, double& y)
{
	if (m1 == obj.m1)
	{
		return false;
	}
	else
	{
		x = (obj.b1 - b1) / (m1 - obj.m1);
		y = m1 * x + b1;
		return true;
	}
}
//print intersection point
void lineType::printIntersectionPoints(lineType& obj, double& x, double& y)
{
	x = (obj.b1 - b1) / (m1 - obj.m1);
	y = m1 * x + b1;
	cout << "Intersection point: (" << x << ", " << y << ')' << endl;
}
//default constructor
lineType::lineType(double x = 0, double y = 0)
{
	setLine(x, y);
}

//varaibles for function beneath
double ep = 1e-6;
//additional default constructor (used chat for the formulas @_@)
lineType::lineType(double a, double b, double c)
{
	if (fabs(b) < ep)
	{
		m1 = INFINITY;
		b1 = NAN;
	}
	else
	{
		m1 = -a / b;
		b1 = c / b;
	}
}





