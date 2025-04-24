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

<<<<<<< Updated upstream
	//THIS IS FOR PART 2
	void yEqualsMxPlusB(double a1, double b1, double c1, double a2, double b2, double c2);
=======
	bool isParallel(lineType& obj);

	bool intersectionPoints(double& x, double& y);

	//bool isParallelogram(lineType& obj1, lineType& obj2, lineType obj3, lineType& obj4);

	void printIntersectionPoints(double& x, double& y);

	void setLine(double x, double y);

	lineType(double x, double y);

	lineType(double a, double b, double c);

	bool intersectionPointsFromFile(double a, double b, double c, double& x, double& y);

	
>>>>>>> Stashed changes
};

#endif