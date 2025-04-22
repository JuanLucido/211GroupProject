#include <iostream>
#include <string>
using namespace std;

#include "lineType.h"

//sets line
void lineType::setLine(double x, double y)
{
	x1 = x;
	y1 = y;
	m1 = y1 / x1;
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
//default constructor
lineType::lineType(double x = 0, double y = 0)
{
	setLine(x, y);
}

