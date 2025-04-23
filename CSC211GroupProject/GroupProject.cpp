#include "lineType.h"
#include <iostream>
#include <string>
using namespace std;

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

	//additional testing for new function (convertLineForm())
	

	/*lineType line;
	double m1, b1, m2, b2;
	while (true) {
		cout << "Enter the slope and y-intercept of the first line (m1 b1): ";
		cin >> m1 >> b1;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please enter two numbers." << endl;
			continue;
		}
		break;
	}
	line.f(m1, b1);
	cout << "the line of f(x) is y = " << line.f(m1, b1) << endl;
	while (true) {
		cout << "Enter the slope and y-intercept of the second line (m2 b2): ";
		cin >> m2 >> b2;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please enter two numbers." << endl;
			continue;
		}
		break;
	}
	line.g(m2, b2);
	cout << "The line of g(x) is y = " << line.g(m2, b2) << endl << endl;
	cout << "This is the equation of both f(x) and g(x) equal to each other " << endl;
	line.equalToEachOther(m1, b1, m2, b2);*/
	return 0;
}
