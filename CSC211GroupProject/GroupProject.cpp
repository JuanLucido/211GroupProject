#include "lineType.h"
#include <iostream>
#include <string>
using namespace std;

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

	cout << "TESTING reasons enter a number for a b and c for the ax+by=c form ";
	double a, b, c;
	cin >> a >> b >> c;
	cout << "enter the numbers for the second line ";
	double d, e, f;
	cin >> d >> e >> f;
	line.yEqualsMxPlusB(a, b, c, d, e, f);

	cout << "TESTING reasons enter a number for a b and c for the ax+by=c form " << endl;
	double g, h, i;
	cin >> g >> h >> i;
	cout << "enter the numbers for the second line " << endl;
	double j, k, l;
	cin >> j >> k >> l;
	line.yEqualsMxPlusB(g, h, i, j, k, l);
	//make bool that turns true if they intersect


}
