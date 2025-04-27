#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#include "lineType.h"

//sets line
void lineType::setLine(double x, double y)
{
	double a, b, c;
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
bool lineType::intersectionPoints(double& x, double& y)
{
	if (m1 == m1)
	{
		return false;
	}
	else
	{
		return true;
	}
}
//print intersection point
void lineType::printIntersectionPoints(double& x, double& y)
{
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

//not even going to lie idk what the hell is happening its like 12 am I'm tried man
bool lineType::intersectionPointsFromFile(double a, double b, double c, double& intX, double& intY)
{
	double otherM, otherB;
	const double epsilon = 1e-6;

	// Handle vertical line: b == 0 means vertical
	if (fabs(b) < epsilon) {
		otherM = INFINITY;
		otherB = NAN;
	}
	else {
		otherM = -a / b;
		otherB = c / b;
	}

	if (fabs(m1 - otherM) < epsilon || (isinf(m1) && isinf(otherM))) {
		return false; // Lines are parallel
	}

	if (isinf(m1)) {
		intX = x1;
		intY = otherM * intX + otherB;
	}
	else if (isinf(otherM)) {
		intX = -c / a;
		intY = m1 * intX + b1;
	}
	else {
		intX = (otherB - b1) / (m1 - otherM);
		intY = m1 * intX + b1;
	}

	return true;
}