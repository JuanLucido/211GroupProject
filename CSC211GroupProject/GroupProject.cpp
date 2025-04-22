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

	//THIS IS FOR PART 2
	//This is for the first 2 set of lines given to us IE 10 2 6 (line 1)  and 20 4 -8 (line 2)
	cout << "TESTING reasons enter a number for a b and c for the ax+by=c form ";
	double a, b, c;
	cin >> a >> b >> c;
	cout << "enter the numbers for the second line ";
	double d, e, f;
	cin >> d >> e >> f;
	//this function converts the lines from ax+by=c form to y=mx+b form as well as states if the lines are parallel or not 
	line.yEqualsMxPlusB(a, b, c, d, e, f);

	//This is for the last 2 set of lines given to us IE 3 -1 -4 (line 3)  and -14 2 0(line 4)
	cout << "TESTING reasons enter a number for a b and c for the ax+by=c form: " << endl;
	//the reason I'm not overwritting the abcdef is because we would need to keep the answer (if its parallel) from the first 2 lines to help determine the shape 
	double g, h, i;
	cin >> g >> h >> i;
	cout << "enter the numbers for the second line: " << endl;
	double j, k, l;
	cin >> j >> k >> l;
	//I just recalled this function because it when we do it gives us the point whcih the last 2 lines intersect
	line.yEqualsMxPlusB(g, h, i, j, k, l);
	//make bool that turns true if they intersect

	/* Determining Shapes
	* Trapeziod: one pair of parallel sides (the other side will eventually intersect)
	* Parallelogram: all sides are parallel but the corners are not 90 degrees 
	* Rhombus: all 4 sides have equal length (every Rhombus is a parallelagrame but not all parallelograms are Rhombus's)
	* Rectangle: all sides are parallel AND the corners are corners are 90 degrees (perpendicular)
	* Square: Similar to rectangle however all sides buts have equal length 
	
	
	
	*/


}
