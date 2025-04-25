#ifndef LINETYPE_H
#define LINETPYE_H

#include <string>
using namespace std;

class lineType {
private:
	double x1, y1, m1, a1, b1, c1, b2;
public:
	double getx1();

	double gety1();

	double getm1();

	bool equalToEachOther(lineType& obj);

	bool isPerpendicular(lineType& obj);

	bool isParallel(lineType& obj);

	bool intersectionPoints(lineType& obj, double& x, double& y);

	//bool isParallelogram(lineType& obj1, lineType& obj2, lineType obj3, lineType& obj4);

	void printIntersectionPoints(double& x, double& y);

	void setLine(double x, double y, double m);

	//lineType(double x, double y);

	lineType(double a, double b, double c);

	
};

#endif