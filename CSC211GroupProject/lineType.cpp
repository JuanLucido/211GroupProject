#include <iostream>
#include <string>
using namespace std;

#include "lineType.h"

string lineType::f(double m, double b) {
	//converts to string that way the 'x' can show up in the equation
	return  to_string(m) + "x + " + to_string(b);
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
	string fx = f(m1, b1);
	string gx = g(m2, b2);
	//Checking if the lines are perpendicular
	if (m1 * m2 == -1)
	{
		cout << "The lines are perpendicular to each other." << endl;
	}
	else
	{
		cout << "The lines are not perpendicular to each other." << endl;
	}
}