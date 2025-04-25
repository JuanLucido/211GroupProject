#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#include "lineType.h"

//sets line
const double ep = 1e-6; 
//used chat to help with the formulas @_@
void lineType::setLine(double a, double b, double c) // reverting to ax+by=c formula
{
	a1 = a;
	b1 = b;
	c1 = c;
	if (fabs(b1) < ep)
	{
		m1 = INFINITY;
		b2 = NAN;
	}
	else
	{
		m1 = -a1 / b1;
		b2 = c1 / b1;
	}
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
	double det = (a1 * obj.b1) - (obj.a1 * b1);
	if (fabs(det) < ep) //is it close to zero ?? ty chatgpt ig
	{
		return false;
	}
	else
	{
		x = (c1 * obj.b1 - obj.c1 * b1) / det;
		y = (a1 * obj.c1 - obj.a1 * c1) / det;
		return true;
	}
}
//print intersection point
void lineType::printIntersectionPoints(double& x, double& y)
{
	cout << "Intersection point: (" << x << ", " << y << ')' << endl;
}
//default constructor
lineType::lineType(double a, double b, double c)
{
	setLine(a,b,c);
}

//sorry for commenting this out it's okay we can bring this back later
//not even going to lie idk what the hell is happening its like 12 am I'm tried man 
//bool lineType::intersectionPointsFromFile(double a, double b, double c, double& intX, double& intY)
//{
//	double otherM, otherB;
//	const double epsilon = 1e-6;
//
//	// Handle vertical line: b == 0 means vertical
//	if (fabs(b) < epsilon) {
//		otherM = INFINITY;
//		otherB = NAN;
//	}
//	else {
//		otherM = -a / b;
//		otherB = c / b;
//	}
//
//	if (fabs(m1 - otherM) < epsilon || (isinf(m1) && isinf(otherM))) {
//		return false; // Lines are parallel
//	}
//
//	if (isinf(m1)) {
//		intX = x1;
//		intY = otherM * intX + otherB;
//	}
//	else if (isinf(otherM)) {
//		intX = -c / a;
//		intY = m1 * intX + b1;
//	}
//	else {
//		intX = (otherB - b1) / (m1 - otherM);
//		intY = m1 * intX + b1;
//	}
//
//	return true;
//}





