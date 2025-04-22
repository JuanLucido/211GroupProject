#ifndef LINETYPE_H
#define LINETPYE_H

#include <string>
using namespace std;

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

	string f(double m, double b);

	string g(double m, double b);

	void equalToEachOther(double m1, double b1, double m2, double b2);

	void isPerpendicular(double m1, double b1, double m2, double b2);

	//THIS IS FOR PART 2
	void yEqualsMxPlusB(double a1, double b1, double c1, double a2, double b2, double c2);
};

#endif