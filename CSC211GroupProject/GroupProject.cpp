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
		cout << "\nPerpendicular to each other? : ";
		if (isPerpendicular(lineA, lineB) == true) {
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
	
	int intX, intY;

	fin.close();
	for (int coi = 0;coi < 3;coi++) {
		cout << "\n---------------------------------------------------------\n\n";
		cout << "Here's Quadrilateral " << coi+1 << "'s Information:\n\n";
		printQuadInfo(quad.at(coi));

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
	cout << "Is this shape a Parallelogram? ";
	if (obj1.get_isParallelogram() == true) {
		cout << "\tYES\n";
	}
	else {
		cout << "\tNO\n";
	}
	cout << "Is this shape a Trapezoid? ";
	if (obj1.get_isTrapezoid() == true) {
		cout << "\tYES\n";
	}
	else {
		cout << "\tNO\n";
	}
	cout << "Is this shape a Rectangle? ";
	if (obj1.get_isRectangle() == true) {
		cout << "\tYES\n";
	}
	else {
		cout << "\tNO\n";
	}
	cout << "Is this shape a Rhombus? ";
	if (obj1.get_isRhombus() == true) {
		cout << "\tYES\n";
	}
	else {
		cout << "\tNO\n";
	}
	cout << "Is this shape a Square? ";
	if (obj1.get_isSquare() == true) {
		cout << "\tYES\n";
	}
	else {
		cout << "\tNO\n";
	}

	obj1.printIntersectionPoints();
}
