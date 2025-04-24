#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "lineType.h"

<<<<<<< Updated upstream
string lineType::f(double m, double b) {
	//converts to string that way the 'x' can show up in the equation
	return  to_string(m) + "x + " + to_string(b);
=======
//sets line
void lineType::setLine(double x, double y)
{
	double a, b, c;
	x1 = x;
	y1 = y;
	m1 = y1 / x1;
	b1 = y1 - m1 * x1;
>>>>>>> Stashed changes
}

//THIS IS FOR PART 2
//A1 A2 B1 B2 and C1 C2 for the 2 lines inputed I know the thing states to read it in from a file but it was more for testing purposes for the math logic
void lineType::yEqualsMxPlusB(double a1, double b1, double c1, double a2, double b2, double c2) {

	cout << endl << endl;
	//just shows the values in ax+by=c form 
	cout << a1 << 'x' << " + " << b1 << 'y' << '=' << c1;
	double m1 = -a1 / b1;//this gives the slope for m in the y=mx+b form 
	double firstLineB = c1 / b1;//give b for the first line
	cout << " To get this to y=mx+b form its y = " << m1 << "x + " << firstLineB << endl;
	cout << m1 << " is the the slope with " << firstLineB << " being the y intercept " << endl;

	double m2 = -a2 / b2;////this gives the slope for m in the y=mx+b form (second line)
	double secondLineB = c2 / b2;//give b for the second line
	////just shows the values in ax+by=c form (for second line)
	cout << a2 << 'x' << " + " << b2 << 'y' << '=' << c2;
	cout << " To get this to y=mx+b form its y = " << m2 << "x + " << secondLineB << endl;
	cout << m2 << " is the the slope with " << secondLineB << " being the y intercept " << endl;
	cout << endl << endl;
	//the is equal to each other was for find if the lines are parallel if they arent it will give the point of intersection for the 2 lines 
	equalToEachOther(m1, firstLineB, m2, secondLineB);
	isPerpendicular(m1, firstLineB, m2, secondLineB);

}

string lineType::g(double m, double b) {
	//converts to tring that way the 'x' can show up in the equation
	return to_string(m) + "x + " + to_string(b);
}

void lineType::equalToEachOther(double m1, double b1, double m2, double b2) {
	string fx = f(m1, b1);
	string gx = g(m2, b2);
	cout << fx << " = " << gx << endl;
	//This if statement is to check if the lines are the same and or parallel
	if (m1 == m2) {
		if (b1 == b2) {
			cout << "The lines are the same (infinitely many solutions)." << endl;
		}
		else {
			cout << "The lines are parallel (no solution)." << endl;
		}
	}
	else {
		//if they arent the same x becomes whatever m1,b1,m2,b2 are divided by each other 
		double x = (b2 - b1) / (m1 - m2);
		cout << "The x value where f(x) = g(x) is: x = " << x << endl;
		double y = (x * m1 + b1);
		cout << "The y value where f(x) = g(x) is: " << y << endl;
	}
}

void lineType::isPerpendicular(double m1, double b1, double m2, double b2)
{
<<<<<<< Updated upstream
	string fx = f(m1, b1);
	string gx = g(m2, b2);
	//Checking if the lines are perpendicular
	if (m1 * m2 == -1)
=======
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
>>>>>>> Stashed changes
	{
		cout << "The lines are perpendicular to each other." << endl;
	}
	else
	{
<<<<<<< Updated upstream
		cout << "The lines are not perpendicular to each other." << endl;
	}
}
=======
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





>>>>>>> Stashed changes
