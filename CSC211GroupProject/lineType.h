#ifndef LINETYPE_H
#define LINETPYE_H

#include <string>
using namespace std;

class lineType {
private:
	double x1, y1, m1;
public:
	double getx1();

	double gety1();

	double getm1();

	void setLine(double x, double y);

	bool equalToEachOther(lineType& obj);

	bool isPerpendicular(lineType& obj);

	lineType(double x, double y);
};

#endif