#include <iostream>
#include <string>
using namespace std;

//THIS FILE AND REPO WAS LAST UPDATED & REVIEWED ON 04/17 @9:05 PM

class lineType {
public:
	//void x_int(double a, double b, double c) {
	//	cout << a << 'x' << " + " << b << 'y' << '=' << c;
	//	//math part where y=0
	//	a + b * 0;
	//	c = c / a;
	//	cout << " The x intercept is " << c << endl;
	//
	//
	//}
	//void y_int(double a, double b, double c) {
	//	cout << a << 'x' << " + " << b << 'y' << '=' << c;
	//	a * 0 + b;
	//	c = c / b;
	//	cout << " The y intercept is " << c << endl;
	//}
	//void x_int2(double a, double b, double c) {
	//	cout << a << 'x' << " + " << b << 'y' << '=' << c;
	//	//math part where y=0
	//	a + b * 0;
	//	c = c / a;
	//	cout << " The x intercept is " << c << endl;
	//
	// testing234234234 dakota's branch//
	//}

	string f(double m, double b) {
		//converts to string that way the 'x' can show up in the equation
		return  to_string(m) + "x + " + to_string(b);
	}

	string g(double m, double b) {
		//converts to tring that way the 'x' can show up in the equation
		return to_string(m) + "x + " + to_string(b);
	}

	void equalToEachOther(double m1, double b1, double m2, double b2) {
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

	void isPerpendicular(double m1, double b1, double m2, double b2)
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
};

int main() {
	lineType line;
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
	line.equalToEachOther(m1, b1, m2, b2);
}
