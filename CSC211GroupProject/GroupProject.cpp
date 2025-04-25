#include "lineType.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//all functions below check for shapes (used chat to help with most of these formulas
bool isParallelogram(lineType& obj1, lineType& obj2, lineType obj3, lineType& obj4)
{
	return obj1.isParallel(obj2) && obj3.isParallel(obj4);
}

bool isTrapezoid(lineType& obj1, lineType& obj2, lineType obj3, lineType& obj4)
{
	bool pair1 = obj1.isParallel(obj2);
	bool pair2 = obj3.isParallel(obj4);
	return pair1 ^ pair2; //XOR operator
}

bool isRectangle(lineType& obj1, lineType& obj2, lineType obj3, lineType& obj4)
{
	return isParallelogram(obj1, obj2, obj3, obj4) && obj1.isPerpendicular(obj3);
}

bool isRhombus(lineType& obj1, lineType& obj2, lineType obj3, lineType& obj4)
{
	return isParallelogram(obj1, obj2, obj3, obj4); //need to add lengths within lineType files to properly work. once we do that we're set.
}

bool isSquare(lineType& obj1, lineType& obj2, lineType obj3, lineType& obj4)
{
	return isRectangle(obj1, obj2, obj3, obj4) && isRhombus(obj1, obj2, obj3, obj4); //same issue here. update rhombus in order to properly fix this.
}
void usierInput() {
	double m1, b1, m2, b2;
	while (true) {
		cout << "Enter 4 numbers (m1, b1, m2, b2). The first 2 will be counted as lineA and the second 2 as lineB: ";
		if (cin >> m1 >> b1 >> m2 >> b2) {
			if (m1 == m2) {
				cout << "Lines are parallel (m1 cannot equal m2). Please re-enter valid values." << endl;
				continue;
			}
			break; // Valid input
		}
		else {
			cin.clear(); // Clear the error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
			cout << "Invalid input. Please enter numeric values." << endl;
		}
	}

	lineType lineA(m1, b1);
	lineType lineB(m2, b2);


	cout << "Does lineA = lineB (1 - yes | 0 - no): " << lineA.equalToEachOther(lineB) << endl;
	cout << "Is lineA parallel to lineB (1 - yes | 0 - no): " << lineA.isParallel(lineB) << endl;

	
	double x, y;
	x = (b2 - b1) / (m1 - m2);
	y = (x * m1 + b1);

   
	cout << "Using printIntersectionPoints for lineA and lineB: " << endl;
	//this is all we had to do which when looking at it makes sense
	if (lineA.intersectionPoints(x, y) == lineB.intersectionPoints(x, y))
	{
		cout << '(' << x << ", " << y << ')' << endl;
	}
	else
	{
		cout << "No intersection points (parallel)." << endl;

	}
}

void readFile() {
	ifstream fin("sets_of_lines.txt");
	if (!fin.is_open()) {
		cerr << "Error: Unable to open file." << endl;
		
	}
	//THIS SHIT FINALLY FUCKING WORKS HOW? IDK BUT IT DOES I'M GOING TO GO CRY NOW
	cout << "\nUsing form converstion functions: " << endl << endl;
	//shows which set of numbers its being read in from
	int lineNum = 1;
	double a, b, c, e, f, g, h, i, j, k, l, m, n;
	while (fin >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l >> m) {

		lineType lineE(a, b, c);
		lineType lineF(e, f, g);

		lineType lineG(h, i, j);
		lineType lineH(k, l, m);

		// Declare variables to store the intersection point
		double intX, intY;

		// Print the intersection of all lines from the file
		cout << "Intersections for set " << lineNum << ":" << endl;

		if (lineE.intersectionPointsFromFile(e, f, g, intX, intY)) {
			cout << "E and F: (" << intX << ", " << intY << ")" << endl;
		}
		else {
			cout << "E and F: No intersection (parallel)" << endl;
		}
		if (lineE.intersectionPointsFromFile(h, i, j, intX, intY)) {
			cout << "E and G: (" << intX << ", " << intY << ")" << endl;
		}
		else {
			cout << "E and G: No intersection(parallel)" << endl;
		}
		if (lineE.intersectionPointsFromFile(k, l, m, intX, intY)) {
			cout << "E and H: (" << intX << ", " << intY << ")" << endl;
		}
		else {
			cout << "E and H: No intersection (parallel)" << endl;
		} 
		if (lineF.intersectionPointsFromFile(h, i, j, intX, intY)) {
			cout << "F and G: (" << intX << ", " << intY << ")" << endl;

		}
		else {
			cout << "F and G: No intersection (parallel)" << endl;
		}
		if (lineF.intersectionPointsFromFile(k, l, m, intX, intY)) {
			cout << "F and H: (" << intX << ", " << intY << ")" << endl;
		}
		else {
			cout << "F and H: No intersection (parallel)" << endl;
		}
		if (lineG.intersectionPointsFromFile(k, l, m, intX, intY)) {
			cout << "G and H: (" << intX << ", " << intY << ")" << endl;
		}
		else {
			cout << "G and H: No intersection (parallel)" << endl;
		}
			
		cout << endl;

		cout << "\nTesting shapes: (only tested functional ones) of the " << lineNum << " set of the lines from the file " << endl;
		cout << "Parallelogram? (1 - yes | 0 - no): " << isParallelogram(lineE, lineF, lineG, lineH) << endl;
		cout << "Rectangle? (1 - yes | 0 - no): " << isRectangle(lineE, lineF, lineG, lineH) << endl;
		cout << "Trapezoid? (1 - yes | 0 - no): " << isTrapezoid(lineE, lineF, lineG, lineH) << endl << endl;

		lineNum++;

	}


	fin.close();

}


//main function
int main() {
	
    int choice;
    cout << "Welcome to the CSC 211 group project choose from the list provided to see what you want to do. " << endl;
    do {
    cout << "1. Type in numbers and find the intersection of 2 lines" << endl;
    cout << "2. Read in from a file to find where the lines intersect and what shape they make." << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice (1-3): ";

    while (!(cin >> choice) || choice < 1 || choice > 3) {
    cin.clear(); // Clear the error flag
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    cout << "Invalid input. Please enter a number between 1 and 3: ";
    }

    switch (choice) {
    case 1:
    usierInput();
    break;
    case 2:
    readFile();
    break;
    }

    } while (choice != 3);

    return 0;
}
