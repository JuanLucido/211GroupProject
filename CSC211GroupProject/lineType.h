#ifndef LINETYPE_H
#define LINETPYE_H

#include <string>
using namespace std;

class lineType {
private:
	double x1, y1, m1, b1;
public:
	double getx1();

	double gety1();

	double getm1();

	void setLine(double x, double y);

	bool equalToEachOther(lineType& obj);

	bool isPerpendicular(lineType& obj);

	bool isParallel(lineType& obj);

	bool intersectionPoints(lineType& obj, double& x, double& y);

	void printIntersectionPoints(lineType& obj, double& x, double& y);

	lineType(double x, double y);
};

#endif