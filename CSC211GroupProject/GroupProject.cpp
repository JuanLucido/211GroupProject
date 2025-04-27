#include "lineType.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

#include <iomanip>
#include <vector>
using namespace std;

const int MAX_SIZE = 5000; //Global variable for max size of user-entered char array

bool entryFailed(char array[], int low, int high, int& choice);

void introPrompt();

void exitPrompt();

void mainMenu();

void printLineInfo(lineType obj1);

void printQuadInfo(quadType obj1);

void userInput() {

	int loops = 0;
	double m1, yInt1, m2, yInt2;

	while (true) {
		cout << "\n---------------------------------------------------------\n\n"
			<< "---------- LINE COMPARISON OPERATIONS ----------\n\n"
			<< "In this section you'll be creating 2 lines as they would be graphed on a Cartesian plane\n"
			<< "(i.e., Format: y = m * x + b)\n\n...";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "\n---------------------------------------------------------\n\n"
			 << "FIRST LINE (Line A):\n"
			 << "Enter a value for 'm' (slope) in either integer or decimal format\n(e.g., 1.0, 1, 5.0, 5,)\n\n"
			 << "Your new 'm' value: ";
		cin >> m1;

		cout << "\n\nNow enter a value for 'b' (y-intercept) in either integer or decimal format\n(e.g., 1.0, 1, 5.0, 5,)\n\n"
			 << "Your new 'b' value: ";
		cin >> yInt1;
		lineType lineA(m1, yInt1);

		cout << "\n---------------------------------------------------------\n\n"
			 << "SECOND LINE (Line B):\n"
			 << "Enter a value for 'm' (slope) in either integer or decimal format\n(e.g., 1.0, 1, 5.0, 5,)\n\n"
			 << "Your new 'm' value: ";
		cin >> m2;

		cout << "\n\nNow enter a value for 'b' (y-intercept) in either integer or decimal format\n(e.g., 1.0, 1, 5.0, 5,)\n\n"
			<< "Your new 'b' value: ";
		cin >> yInt2;
		lineType lineB(m2, yInt2);

		cout << "\n---------------------------------------------------------\n\n"
			 << "Here are the properties of your Lines:\n\n"; 
		cout << "LineA:\n";
		printLineInfo(lineA);
		cout << "\nLineB:\n";
		printLineInfo(lineB);

		cout << "Comparison of LineA & LineB:\n\n"
			<< "Equal to each other? : ";
		if (equalToEachOther(lineA, lineB) == true) {
			cout << "YES";
		}
		else {
			cout << "NO";
		}
		cout << "\nParallel to each other? : ";
		if (isParallel(lineA, lineB) == true) {
			cout << "YES";
		}
		else {
			cout << "NO";
		}
		
		double x = 0.0, y = 0.0;
		plotIntersection(lineA, lineB, x, y);

		cout << "\nDo they intersect? : ";
		if (isParallel(lineA, lineB) == false) {
			cout << "YES. Intersection Point is at.... (" << x << ", " << y << " )\n";
		}
		else {
			cout << "NO. Both lines are parallel and will NEVER intersect!!!\n";
		}
		cout << "\n...";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		break;
	}
}

void readFile() {
	vector<quadType> quad;
	ifstream fin("sets_of_lines.txt");
	if (!fin.is_open()) {
		cerr << "Error: Unable to open file." << endl;
		
	}
	//shows which set of numbers its being read in from
	int lineNum = 1;
	double a, b, c, e, f, g, h, i, j, k, l, m;
	for (int coi = 0;coi < 3;coi++) {
		fin >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l >> m;
		lineType lineE(a, b, c);
		lineType lineF(e, f, g);

		lineType lineG(h, i, j);
		lineType lineH(k, l, m);

		quadType temp(lineE,lineF,lineG,lineH);
		quad.push_back(temp);
		lineNum++;
	}
	
	fin.close();
	for (int coi = 0;coi < 3;coi++) {
		printQuadInfo(quad.at(coi));
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	}

}

int main() {
	introPrompt();
	mainMenu();
	exitPrompt();
	return 0;
}

//Returns true/false within while loop parentheses; only works on integers, ie., when user selects a menu option
bool entryFailed(char array[], int low, int high, int& choice) { 

	int conversion = 0;

	if (strlen(array) > 2) {} //Converts Char array[] to statically cast integer
	else if (strlen(array) == 1) { conversion = static_cast<int>(array[0]) - 48; }

	//else if (strlen(array) == 2) {
	//	conversion = 10 * (static_cast<int>(array[0]) - 48) + (static_cast<int>(array[1]) - 48);
	//}

	if (conversion < low || conversion > high) { //Returns error until user inputs valid choice
		cin.clear(); //clears error flags
		cerr << "\nINVALID INPUT! Enter ONLY what the prompt says!!! ...";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return true;
	}
	else { //If user entered valid choice, exits loop
		choice = conversion; //sets conversion of character array to integer needed to menu/user
		return false;
	}
}

void introPrompt()
{
	cout << "========== WELCOME TO Team T.G.F.Y's 211 Group Project 1.0 ==========\n\n"
		<< "This programs helps analyze mathematical representations of 'lines',\ni.e., y = mx + b, by comparing them.\n\n"
		<< "=====================================================================\n\n"
		<< "Any time you see '...' the program stalled. Press [ENTER] to continue!\n\n...";

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void exitPrompt()
{
	cout << "\n===================================================================\n\n";
	cout << "Thank you for using our team's 211 Group Project. Goodbye!!!\n\n...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void mainMenu()
{
	while (true) {
		char selection[MAX_SIZE];
		int choice;
		int low = 1; //locally defined lower and upper limits
		int high = 3;

		do {
			cout << "\n---------------------------------------------------------\n\n"
				<< "---------- WELCOME TO THE MAIN MENU ----------\n\n"
				<< "What would you like to do?\n\n"
				<< "1. Type in slope/y-intercept of 2 lines (y = mx + b) to find their intersection point\n"
				<< "2. Read in line data from 'sets_of_Lines.txt' for shape identification\n"
				<< "3. Exit\n\n"
				<< "Your choice: ";

			cin.getline(selection, MAX_SIZE);

		} while (entryFailed(selection, low, high, choice)); //Checks validity of user input

		switch (choice) {
		case 1:
			userInput();
			break;
		case 2:
			readFile();
			break;
		case 3:
			return; //Exits void function
		}
	}
}

void printLineInfo(lineType obj1) {
	cout << "'m' value (slope): " << obj1.get_m() << "\n'b' value (y-intercept): " << obj1.get_y_intercept() << endl;
	cout << "Slop-Intercept format of LINE: " << obj1.get_eqnYMXB() << "\n\n";
	cout << "'A' value: " << obj1.get_a() << "\n'B' value: " << obj1.get_b() << "\n'c' value: " << obj1.get_c() << endl;
	cout << "Standard Form of LINE: " << obj1.get_eqnABC() << "\n\n";
}

//call the getters except for shapeName
void printQuadInfo(quadType obj1)
{
	obj1.get_isParallelogram();
	if (obj1.get_isParallelogram() == true) {
		cout << "THIS WORKS";
	}
	else {
		cout << "not parallelogram";
	}
	obj1.get_isTrapezoid();
	if (obj1.get_isTrapezoid() == true) {
		cout << "This is a trapizod" << endl;
	}
	else {
		cout << "Not a trap" << endl;
	}
	obj1.get_isRectangle();
	
	obj1.get_isRhombus();
	obj1.get_isSquare();

	obj1.get_intersect1();
	obj1.get_intersect2();
	obj1.get_intersect3();
	obj1.get_intersect4();

using namespace std;

//Pull Request rest on main branch (4/25)

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
		//////////
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
