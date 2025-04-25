#include "lineType.h"
#include <iostream>
#include <string>
using namespace std;

//NUKING MAIN ON FRIDAY (4/25)

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
	lineType lineA(2, 4);
	lineType lineB(4, 8);
	lineType lineC(1, -2);
	lineType lineD(2, 6);

	cout << "Does lineA = lineB (1 - yes | 0 - no): " << lineA.equalToEachOther(lineB) << endl;
	cout << "Is lineA parallel to lineB (1 - yes | 0 - no): " << lineA.isParallel(lineB) << endl;
	cout << "Is lineA perpendicular to lineC (1 - yes | 0 - no): " << lineA.isPerpendicular(lineC) << endl << endl;

	double x, y;
	cout << "Using printIntersectionPoints for lineA and lineC: " << endl;
	if (lineA.intersectionPoints(lineC, x, y))
	{
		cout << '(' << x << ", " << y << ')' << endl;
	}
	else
	{
		cout << "No intersection points (parallel)." << endl;
	}

	cout << "\nUsing form converstion functions: " << endl;
	lineType lineE(2, -1, 4);
	lineType lineF(-1, -1, -4);
	lineType lineG(1, 1, 2);

	cout << "Is lineE parallel to lineF (1 - yes | 0 - no): " << lineE.isParallel(lineF) << endl;
	cout << "Is lineE perpendicular to lineG (1 - yes | 0 - no): " << lineE.isPerpendicular(lineG) << endl;

	cout << "Intersection of lineE and lineG: ";
	if (lineE.intersectionPoints(lineG, x, y)) {
		cout << '(' << x << ", " << y << ')' << endl;
	}
	else {
		cout << "No intersection." << endl;
	}

	cout << "\nTesting shapes: (only tested functional ones)" << endl;
	cout << "Parallelogram? (1 - yes | 0 - no): " << isParallelogram(lineA, lineB, lineC, lineD) << endl;
	cout << "Rectangle? (1 - yes | 0 - no): " << isRectangle(lineA, lineB, lineC, lineD) << endl;
	cout << "Trapezoid? (1 - yes | 0 - no): " << isTrapezoid(lineA, lineB, lineC, lineD) << endl;

	return 0;
}
