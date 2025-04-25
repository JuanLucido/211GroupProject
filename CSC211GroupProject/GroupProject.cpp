#include "lineType.h"
#include <iostream>
#include <string>
using namespace std;

//all functions below check for shapes (used chat to help with most of these formulas
bool isParallelogram(lineType& obj1, lineType& obj2, lineType obj3, lineType& obj4)
{
	return obj1.isParallel(obj2) && obj3.isParallel(obj4);
}

bool isTrapezoid(lineType& obj1, lineType& obj2, lineType obj3, lineType& obj4)
{
	bool pair1 = obj1.isParallel(obj2);
	bool pair2 = obj3.isParallel(obj4);
	return pair1 ^ pair2; //XOR operator
}

bool isRectangle(lineType& obj1, lineType& obj2, lineType obj3, lineType& obj4)
{
	return isParallelogram(obj1, obj2, obj3, obj4) && obj1.isPerpendicular(obj3);
}

bool isRhombus(lineType& obj1, lineType& obj2, lineType obj3, lineType& obj4)
{
	return isParallelogram(obj1, obj2, obj3, obj4); //need to add lengths within lineType files to properly work. once we do that we're set.
}

bool isSquare(lineType& obj1, lineType& obj2, lineType obj3, lineType& obj4)
{
	return isRectangle(obj1, obj2, obj3, obj4) && isRhombus(obj1, obj2, obj3, obj4); //same issue here. update rhombus in order to properly fix this.
}


//main function
int main() {
	/*double m1, b1, m2, b2;
	cin >> m1 >> b1 >> m2 >> b2;
	lineType lineA(m1, b1);
	lineType lineB(m1, b2);
	lineType lineC(1, -2);
	lineType lineD(2, 6);

	cout << "Does lineA = lineB (1 - yes | 0 - no): " << lineA.equalToEachOther(lineB) << endl;
	cout << "Is lineA parallel to lineB (1 - yes | 0 - no): " << lineA.isParallel(lineB) << endl;
	//cout << "Is lineA perpendicular to lineC (1 - yes | 0 - no): " << lineA.isPerpendicular(lineC) << endl << endl;

	double x, y;
	x = (b2 - b1) / (m1 - m2);
	y = (x * m1 + b1);
	cout << "Using printIntersectionPoints for lineA and lineB: " << endl;
	//this is all we had to do which when looking at it makes sense
	if (lineA.intersectionPoints(x, y) == lineB.intersectionPoints(x, y))
	{
		cout << '(' << x << ", " << y << ')' << endl;
	}
	else
	{
		cout << "No intersection points (parallel)." << endl;
		
	}*/

	////THIS SHIT FINALLY FUCKING WORKS HOW? IDK BUT IT DOES I'M GOING TO GO CRY NOW
	//cout << "\nUsing form converstion functions: " << endl;
	//cout << "Input the numbers of line E and G(TESTING THIS IS SUPPOSED TO READ IN FROM) ";
	//double a, b, c, e, f, g, h, i, j, k, l, m, n;

	//THIS SHIT FINALLY FUCKING WORKS HOW? IDK BUT IT DOES I'M GOING TO GO CRY NOW
	cout << "\nUsing form converstion functions: " << endl;
	cout << "Input the numbers of line E and G(TESTING THIS IS SUPPOSED TO READ IN FROM) ";
	double a, b, c, e, f, g, h, i, j, k, l, m, n;

	// Input coefficients for line E and F (Standard form: Ax + By = C)
	cin >> a >> b >> c >> e >> f >> g;

	// Initialize line objects for E and F
	lineType lineE(a, b, c);
	lineType lineF(e, f, g);

	// Input coefficients for line G and H (Standard form: Ax + By = C)
	cin >> h >> i >> j >> k >> l >> m;

	// Initialize line objects for G and H
	lineType lineG(h, i, j);
	lineType lineH(k, l, m);

	// Declare variables to store the intersection point
	double intX, intY;

	//// Print the intersection of lineE and lineG
	//cout << "Intersection of lineE and lineG: ";
	//if (lineE.intersectionPointsFromFile(h, i, j, intX, intY)) {
	//	cout << "(" << intX << ", " << intY << ")" << endl;
	//}
	//else {
	//	cout << "No intersection (parallel lines)." << endl;
	//}

	///*cout << "\nTesting shapes: (only tested functional ones)" << endl;
	//cout << "Parallelogram? (1 - yes | 0 - no): " << isParallelogram(lineA, lineB, lineC, lineD) << endl;
	//cout << "Rectangle? (1 - yes | 0 - no): " << isRectangle(lineA, lineB, lineC, lineD) << endl;
	//cout << "Trapezoid? (1 - yes | 0 - no): " << isTrapezoid(lineA, lineB, lineC, lineD) << endl;*/

	return 0;
}
