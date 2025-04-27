#ifndef LINETYPE_H
#define LINETPYE_H

#include <cstdlib>
#include <string>
using namespace std;

class lineType { //Creates line 'objects'
private:
	double m, y_intercept;	//Part 1 variables
	double a, b, c;			//Part 2 variables

	string eqnYMXB;	//Y = MX + B
	string eqnABC;	//AX + BY = C

	bool isVerticalLine; //Can only be set 'true' in AX + BY = C, via setLine2 function

public:
	//Getter Functions
	double get_m() { return m; }
	double get_y_intercept() { return y_intercept; }
	double get_a() { return a; }
	double get_b() { return b; }
	double get_c() { return c; }
	string get_eqnYMXB() { return eqnYMXB; }
	string get_eqnABC() { return eqnABC; }
	bool get_isVerticalLine() { return isVerticalLine; }

	//Setter Functions
	void set_m(double input) { m = input; }
	void set_y_intercept(double input) { y_intercept = input; }
	void set_a(double input) { a = input; }
	void set_b(double input) { b = input; }
	void set_c(double input) { c = input; }
	void set_eqnYMXB(string input) { eqnYMXB = input; };
	void set_eqnABC(string input) { eqnABC = input; }
	void set_isVerticalLine(bool input) { isVerticalLine = input; }

	//Constructors - calls setLine functions
	lineType();									//Default
	lineType(double m1, double y_intercept1);	//Part 1
	lineType(double a1, double b1, double c1);	//Part 2

	//Functions for setting all private variable values
	void setLine0();								//Default
	void setLine1(double m1, double y_intercept1);	//Part 1
	void setLine2(double a1, double b1, double c1);	//Part 2 

	//Overload Assignment Operator ( = ); Used when loading lines to quadType object in Part 2
	lineType& operator=(const lineType& source);
};

class quadType { //Quadrilateral composed from comparison of 'lineType objects' intersecting
private:
	string shapeName;	

	bool isParallelogram;	//True if slopes of opposing sides are equal && opposing side equal in length
	bool isTrapezoid;		//True if only 1 pair of opposite sides is parallel
	bool isRectangle;		//True if Parallelogram && sides are perpendicular to each other
	bool isRhombus;			//True if all sides are equal - which also means its a Parallelogram
	bool isSquare;			//True if quad is both Rhombus && Rectangle

	string intersect1;
	string intersect2;
	string intersect3;
	string intersect4;

	//Would add additional bool variable to determine if intersection of lines DOESN'T happen, 
	//but ain't nobody got time fuh dat! - JUAN

public:
	lineType line1, line2, line3, line4; //Lines 1 & 2 are opposite each other, so are Lines 3 & 4

	//Getter Functions
	string get_shapeName() { return shapeName; }
	bool get_isParallelogram() { return isParallelogram; }
	bool get_isTrapezoid() { return isTrapezoid; }
	bool get_isRectangle() { return isRectangle; }
	bool get_isRhombus() { return isRhombus; }
	bool get_isSquare() { return isSquare; }
	string get_intersect1() { return intersect1; }
	string get_intersect2() { return intersect2; }
	string get_intersect3() { return intersect3; }
	string get_intersect4() { return intersect4; }

	//Setter Functions
	void set_shapeName(string input) { shapeName = input; }
	void set_isParallelogram(bool input) { isParallelogram = input; }
	void set_isTrapezoid(bool input) { isTrapezoid = input; }
	void set_isRectangle(bool input) { isRectangle = input; }
	void set_isRhombus(bool input) { isRhombus = input; }
	void set_isSquare(bool input) { isSquare = input; }
	void set_intersect1(string input) { intersect1 = input; }
	void set_intersect2(string input) { intersect2 = input; }
	void set_intersect3(string input) { intersect3 = input; }
	void set_intersect4(string input) { intersect4 = input; }

	//Constructor
	quadType(lineType obj1, lineType obj2, lineType obj3, lineType obj4);
	
	void setIntersections(lineType objA, lineType objB, lineType objC, lineType objD);
	
	void printIntersectionPoints();

	double calcDistance(lineType obj1, lineType obj2, lineType obj3);

	void parallelogramTest(lineType objA, lineType objB, lineType objC, lineType objD);

	void trapezoidTest(lineType objA, lineType objB, lineType objC, lineType objD);

	void rectangleTest(lineType objA, lineType objB, lineType objC, lineType objD);
	
	void rhombusTest(lineType objA, lineType objB, lineType objC, lineType objD);

	void squareTest();

	//Add print 'printQuadInfo' function?
	
};

//General Purpose functions for Part 1 & 2 below:
bool equalToEachOther(lineType obj1, lineType obj2);
bool isPerpendicular(lineType obj1, lineType obj2);
bool isParallel(lineType obj1, lineType obj2);

//Used to plot intersections of any 2 lines
void plotIntersection(lineType objA, lineType objB, double& x1, double& y1);



#endif