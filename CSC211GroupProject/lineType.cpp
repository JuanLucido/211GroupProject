#include <iostream>
#include <string>
using namespace std;

#include "lineType.h"

void lineType::setLine(double x, double y)
{
	x1 = x;
	y1 = y;
	m1 = y1 / x1;
}

double lineType::getx1()
{
	return x1;
}

double lineType::gety1()
{
	return y1;
}

double lineType::getm1()
{
	return m1;
}

bool lineType::equalToEachOther(lineType& obj)
{
	return (x1 == obj.x1 && y1 == obj.y1);
}

bool lineType::isPerpendicular(lineType& obj)
{
	return ((m1 * obj.m1) == -1);
}

lineType::lineType(double x = 0, double y = 0)
{
	setLine(x, y);
}

