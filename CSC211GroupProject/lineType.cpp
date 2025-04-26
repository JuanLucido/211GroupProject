#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;

#include "lineType.h"

/********************************************************/
/****** Class 'lineType's FUNCTION DEFINITIONS!!!!! *****/
/********************************************************/

//Constructors - calls setLine functions
lineType::lineType() { setLine0(); }												//Default
lineType::lineType(double m1, double y_intercept1) { setLine1(m1, y_intercept1); }	//Part 1
lineType::lineType(double a1, double b1, double c1) { setLine2(a1, b1, c1); }		//Part 2

//Functions for setting all private variable values in Part 1
void lineType::setLine0() 
{
	string tempString1, tempString2;

	// Section: Y = MX + B; Defaults values to 1.0
	set_m(1.0);
	set_y_intercept(1.0);
	tempString1 = "Y = " + to_string(get_m()) + " * X + " + to_string(get_y_intercept());
	set_eqnYMXB(tempString1);

	// Section: AX + BY = C
	set_a(get_m());
	set_b(-1.0);
	set_c(-1 * get_y_intercept());
	tempString2 = to_string(get_a()) + " * X + " + to_string(get_b()) + " * Y = " + to_string(get_c());
	set_eqnABC(tempString2);

	set_isVerticalLine(false);

	// Calculation for A, B, C values in this function is based on calculation below:
	// y = m*x + b  =>  A*x - B*y = - C , where B = -1.0 always, and C = (-1 * y_intercept)
}

void lineType::setLine1(double m1, double y_intercept1) //This needs foolproofing for high/Infinite slope values???
{
	string tempString1, tempString2;

	// Section: Y = MX + B
	set_m(m1);
	set_y_intercept(y_intercept1);
	tempString1 = "Y = " + to_string(get_m()) + " * X + " + to_string(get_y_intercept());
	set_eqnYMXB(tempString1);

	// Section: AX + BY = C
	set_a(get_m());
	set_b(-1.0);
	set_c(-1*get_y_intercept());
	tempString2 = to_string(get_a()) + " * X + " + to_string(get_b()) + " * Y = " + to_string(get_c());
	set_eqnABC(tempString2);

	set_isVerticalLine(false);

	// Calculation for A, B, C values in this function is based on calculation below:
	// y = m*x + b  =>  A*x - B*y = - C , where B = -1.0 always, and C = (-1 * y_intercept)
}

//Functions for setting all private variable values in Part 2
void lineType::setLine2(double a1, double b1, double c1)
{
	string tempString1, tempString2;

	// Section: AX + BY = C
	set_a(a1);
	set_b(b1);
	set_c(c1);
	tempString1 = to_string(get_a()) + " * X + " + to_string(get_b()) + " * Y = " + to_string(get_c());
	set_eqnABC(tempString1);

	// Section: Y = MX + B
	double ep = 1e-6;						//'ep' = short for 'epsilon'. Represents (very cloes to) zero
	if (get_b() == 0 || get_b() < ep) {		//If B == 0, then you have a vertical line
		set_m(INFINITY);					//Vertical lines have infinite slope
		set_y_intercept(NAN);				//NAN = Not A Number; Vertical lines don't have y-intercept
		set_isVerticalLine(true);
		tempString2 = "THIS IS A VERTICAL LINE: It cannot be expressed in 'Y = MX + B' format";
		set_eqnYMXB(tempString2);
	}
	else {
		set_m(get_c() / get_b());
		set_y_intercept((-1 * get_a()) / get_b());
		set_isVerticalLine(false);
		tempString2 = "Y = " + to_string(get_m()) + " * X + " + to_string(get_y_intercept());
		set_eqnYMXB(tempString2);
	}

	// Calculation for M, Y_INTERCEPT values in this function is based on calculation below:
	// A*x + B*y = C  =>  y = (C/B) - (A/B) * x
}

//Overload Assignment Operator ( = ); Used when loading lines to quadType object
lineType& lineType::operator=(const lineType& source) {
	//cout << "Overload Assignment Called." << endl;
	this->m = source.m;
	this->y_intercept = source.y_intercept;
	this->a = source.a;
	this->b = source.c;
	this->eqnYMXB = source.eqnYMXB;
	this->eqnABC = source.eqnABC;
	this->isVerticalLine = source.isVerticalLine;
}

//Add print 'printLineInfo' function?

/********************************************************/
/****** Class 'quadType's FUNCTION DEFINITIONS!!!!! *****/
/********************************************************/

//Constructor
quadType::quadType(lineType obj1, lineType obj2, lineType obj3, lineType obj4) 
{
	line1 = obj1;
	line2 = obj2;
	line3 = obj3;
	line4 = obj4;
	setIntersections(line1, line2, line3, line4);
	parallelogramTest(line1, line2, line3, line4);
	trapezoidTest(line1, line2, line3, line4);
	rectangleTest(line1, line2, line3, line4);
	rhombusTest(line1, line2, line3, line4);
	squareTest();
}

void quadType::setIntersections(lineType objA, lineType objB, lineType objC, lineType objD)
{
	double x = 0.0, y = 0.0;
	string temp;

	plotIntersection(objA, objC, x, y); //Line 1 intersection of Line 3
	temp = "( " + to_string(x) + " , " + to_string(y) + " )";
	set_intersect1(temp);

	plotIntersection(objA, objD, x, y); //Line 1 intersection of Line 4
	temp = "( " + to_string(x) + " , " + to_string(y) + " )";
	set_intersect2(temp);

	plotIntersection(objB, objC, x, y); //Line 2 intersection of Line 3
	temp = "( " + to_string(x) + " , " + to_string(y) + " )";
	set_intersect3(temp);

	plotIntersection(objB, objD, x, y); //Line 2 intersection of Line 4
	temp = "( " + to_string(x) + " , " + to_string(y) + " )";
	set_intersect4(temp);
}

void quadType::printIntersectionPoints()
{
	cout << "Intersection points as would be seen on a 2-D Cartesian Plane:\n\n"
		 << get_intersect1() << endl << get_intersect2() << endl
		 << get_intersect3() << endl << get_intersect4() << endl << endl;
}

double quadType::calcDistance(lineType obj1, lineType obj2, lineType obj3)
{
	double x1, x2, y1, y2, distance;

	//Find (x, y) coordinate when f(x) - g(x) = 0, where solving for x gives y
	//The following is algebra for solving mx + b = mx + b, against Line [1 or 2] vs Line 3 & 4
	x1 = (obj2.get_y_intercept() - obj1.get_y_intercept()) / (obj1.get_m() - obj2.get_m()); //
	x2 = (obj3.get_y_intercept() - obj1.get_y_intercept()) / (obj1.get_m() - obj3.get_m());
	y1 = obj1.get_m() * x1 + obj1.get_y_intercept();
	y2 = obj1.get_m() * x2 + obj1.get_y_intercept();

	//Distance formula
	distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

	return distance;
}

void quadType::parallelogramTest(lineType objA, lineType objB, lineType objC, lineType objD)
{
	if (isParallel(objA, objB) == true && isParallel(objC, objD) == true 
		&& calcDistance(objA, objC, objB) == calcDistance(objB, objC, objD)) {
		set_isParallelogram(true);
	}
	else { set_isParallelogram(false); }
}

void quadType::trapezoidTest(lineType objA, lineType objB, lineType objC, lineType objD) 
{
	if (isParallel(objA, objB) ^ isParallel(objC, objD)) { set_isTrapezoid(true); } //XOR operator
	else { set_isTrapezoid(false); }
}

void quadType::rectangleTest(lineType objA, lineType objB, lineType objC, lineType objD)
{
	if (get_isParallelogram == false) {
		set_isRectangle(false);
	}
	else if (isPerpendicular(objA, objC) == true && isPerpendicular(objA, objD) == true
		&& isPerpendicular(objB, objC) == true && isPerpendicular(objB, objD) == true) {
		set_isRectangle(true);
	}
}

void quadType::rhombusTest(lineType obj1, lineType obj2, lineType obj3, lineType obj4)
{
	if (calcDistance(obj3, obj1, obj2) == calcDistance(obj1, obj3, obj4) 
		== calcDistance(obj2, obj3, obj4) == calcDistance(obj4, obj1, obj2)) {
		set_isRhombus(true);
	}
	else { set_isRhombus(false); }
}

void quadType::squareTest() {
	if (get_isRhombus() == true && get_isRectangle() == true) { set_isSquare(true); }
	else { set_isSquare(false); }
}

//Add print 'printQuadInfo' function?

/********************************************************/
/****** General Purpose FUNCTION DEFINITIONS!!!!! *******/
/********************************************************/

//For 'return' command: If statement in (parentheses) is true, returns TRUE, else FALSE
bool equalToEachOther(lineType obj1, lineType obj2)
{ return (obj1.get_m() == obj2.get_m() && obj1.get_y_intercept() == obj2.get_y_intercept()); }

bool isPerpendicular(lineType obj1, lineType obj2)
{ return (obj1.get_m() * obj2.get_m() == -1); }

bool isParallel(lineType obj1, lineType obj2)
{ return (obj1.get_m() == obj2.get_m()); }

//Used to plot intersections of any 2 lines
void plotIntersection(lineType objA, lineType objB, double& x1, double& y1)
{
	x1 = (objB.get_y_intercept() - objA.get_y_intercept()) / (objA.get_m() - objB.get_m());
	y1 = objA.get_m() * x1 + objA.get_y_intercept();
}

//Used for Part 1 loop
void changeLine(lineType& objA, double m0, double yInt0)
{
	objA.setLine1(m0, yInt0);
}