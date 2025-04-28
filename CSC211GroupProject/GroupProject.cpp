#include "lineType.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;

const int MAX_SIZE = 5000; //Global variable for max size of user-entered char array

bool entryFailed(char array[], int low, int high, int& choice);

bool decimalFailed(char array[], double& choice);

void introPrompt();

void exitPrompt();

void mainMenu();

void opsComplete();

void printLineInfo(lineType obj1);

void printQuadInfo(quadType obj1);

void userInput() {

	int loops = 0;
	double m1, m2, yInt1, yInt2;

	while (true) {
		cout << "\n---------------------------------------------------------\n\n"
			<< "               LINE COMPARISON OPERATIONS\n\n"
			<< "In this section you'll be creating 2 lines as they would be\n" 
			<< "graphed on a Cartesian plane (i.e., Format: y = m * x + b)\n\n"
			<< "Enter numbers only in integer or decimal format (1, 1.0)\n\n....";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		char input[MAX_SIZE];
		double decimal;

		cout << "\n---------------------------------------------------------\n\n"
			<< "FIRST LINE (Line A):\n\n";

		do {
			cout << "Enter Line A's 'm' value (slope): ";

			cin.getline(input, MAX_SIZE);
			if (cin.fail()) {
				cin.clear(); //clears error flags
				cerr << "\nINVALID INPUT! Enter ONLY what the prompt says!!! ...\n";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}
		} while (decimalFailed(input, decimal)); //Checks validity of user input
		
		m1 = decimal;

		do {
			cout << "\nNow Line A's 'b' value (y-intercept): ";

			cin.getline(input, MAX_SIZE);
			if (cin.fail()) {
				cin.clear(); //clears error flags
				cerr << "\nINVALID INPUT! Enter ONLY what the prompt says!!! ...\n";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}
		} while (decimalFailed(input, decimal)); //Checks validity of user input

		yInt1 = decimal;

		lineType lineA(m1, yInt1);

		cout << "\n---------------------------------------------------------\n\n"
			<< "SECOND LINE (Line B):\n\n";

		do {
			cout << "Enter Line B's 'm' value (slope): ";

			cin.getline(input, MAX_SIZE);
			if (cin.fail()) {
				cin.clear(); //clears error flags
				cerr << "\nINVALID INPUT! Enter ONLY what the prompt says!!! ...\n";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}
		} while (decimalFailed(input, decimal)); //Checks validity of user input

		m2 = decimal;


		do {
			cout << "\nEnter Line B's 'b' value (y-intercept): ";

			cin.getline(input, MAX_SIZE);
			if (cin.fail()) {
				cin.clear(); //clears error flags
				cerr << "\nINVALID INPUT! Enter ONLY what the prompt says!!! ...\n";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}
		} while (decimalFailed(input, decimal)); //Checks validity of user input

		yInt2 = decimal;

		lineType lineB(m2, yInt2);

		cout << "\n---------------------------------------------------------\n\n"
			 << "Here are the properties of your Lines ..."; 
		cout << "\n\nLineA:\n\n";
		printLineInfo(lineA);

		cout << "...";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "\nLineB:\n\n";
		printLineInfo(lineB);

		cout << "...";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "\n---------------------------------------------------------\n\n";

		cout << "Comparison of LineA & LineB:\n\n"
			<< "Equal to each other?";
		if (equalToEachOther(lineA, lineB) == true) {
			cout << setw(13) << setfill('.') << "YES";
		}
		else {
			cout << setw(13) << setfill('.') << "NO";
		}
		cout << "\nPerpendicular to each other?";
		if (isPerpendicular(lineA, lineB) == true) {
			cout << setw(6) << setfill('.') << "YES";
		}
		else {
			cout << setw(5) << setfill('.') << "NO";
		}
		cout << "\nParallel to each other?";
		if (isParallel(lineA, lineB) == true) {
			cout << setw(10) << setfill('.') << "YES";
		}
		else {
			cout << setw(10) << setfill('.') << "NO";
		}
		
		double x = 0.0, y = 0.0;
		plotIntersection(lineA, lineB, x, y);

		cout << "\nDo they intersect?";
		if (isParallel(lineA, lineB) == false) {
			cout << setw(13) << setfill('.') << "" <<"YES, Intersection Point at: ( " << x << ", " << y << " )\n";
		}
		else {
			cout << setw(16) << setfill('.') << "NO\n";
		}
		cout << "\n...";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		opsComplete();
		break;
	}
}

void readFile() {
	vector<quadType> quad;
	ifstream fin("sets_of_lines.txt");
	
	cout << "\n---------------------------------------------------------\n\n"
		<< "           QUADRILATERAL ANALYSIS OPERATIONS\n\n"
		<< "In this section you'll be reading in 3 sets of shapes from\n"
		<< "a text file containing 4 lines- each in Ax + By = C format.\n\n"
		<< "The intersection of these 4 lines will form a quadrilateral\nshape for analysis!"
		<< "\n\n....";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	
	cout << "\n---------------------------------------------------------\n\n"
		<< "Reading in 'sets_of_Lines.txt' file data now ...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	if (!fin.is_open()) {
		cerr << "Error: Unable to open file." << endl;
		
	}
	//shows which set of numbers its being read in from
	int loops = 0;
	double a, b, c, e, f, g, h, i, j, k, l, m;
	while (!fin.eof()) {
		fin >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l >> m;
		lineType lineE(a, b, c);
		lineType lineF(e, f, g);

		lineType lineG(h, i, j);
		lineType lineH(k, l, m);

		quadType temp(lineE,lineF,lineG,lineH);
		quad.push_back(temp);
		loops++;
	}

	fin.close();
	for (int coi = 0;coi < loops;coi++) {
		cout << "\n---------------------------------------------------------\n\n";
		cout << "Here's Quadrilateral " << coi+1 << "'s Information:\n\n";
		printQuadInfo(quad.at(coi));

		cout << "...";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		char selection[MAX_SIZE];
		int choice;
		int low = 1; //locally defined lower and upper limits
		int high = 2;

		do {
			cout << "\n\nWould you like to see Quadrilateral [" << coi+1 << "]'s line data ? \n\n"
				<< "1. YES\n"
				<< "2. NO (continues to next Quadrilateral)\n\n"
				<< "Your choice: ";

			cin.getline(selection, MAX_SIZE);

		} while (entryFailed(selection, low, high, choice));

		switch(choice) {
		case 1: {
			cout << "\n---------------------------------------------------------\n\n";
			cout << endl << "---------  Quadrilateral [" << coi + 1 << "]'s Line 1  ---------\n\n";
			printLineInfo(quad.at(coi).line1);
			cout << "\n[ENTER] to continue to next line ...";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << endl << "\n---------  Quadrilateral [" << coi + 1 << "]'s Line 2  ---------\n\n";
			printLineInfo(quad.at(coi).line2);
			cout << "...";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << endl << "\n---------  Quadrilateral [" << coi + 1 << "]'s Line 3  ---------\n\n";
			printLineInfo(quad.at(coi).line3);
			cout << "...";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << endl << "\n---------  Quadrilateral [" << coi + 1 << "]'s Line 4  ---------\n\n";
			printLineInfo(quad.at(coi).line4);
			cout << "...";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		case 2: {
			if (coi == loops - 1) {
				cout << "\n\nEnd of file data reached ...";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}
			cout << "\n\nContinuing to Quadrilateral [" << coi + 2 <<"] ...";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		}
	}
	opsComplete();
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

//Returns true/false within while loop parentheses; only works on decimal entry
bool decimalFailed(char array[], double& choice) {

	double conversion = 0.0;

	int decPos = NAN;
	int preDec = NAN;
	int postDec = NAN;
	int loops = 0;
	bool hasDec = false;

	//First for loop check for erroneous user entry
	for (int i = 0; i < strlen(array) - 1; i++) 
	{
		if (!isdigit(array[i]) && array[i] != '.')
		{
			cin.clear(); //clears error flags
			cerr << "\nINVALID INPUT! Enter ONLY what the prompt says!!! ...\n";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return true;
		}
		else if (array[i] == '.')
		{
			decPos = i;
			preDec = i - 1;
			hasDec = true;
		}
		else if (i == strlen(array) - 2) 
		{
			//postDec = i - decPos+1;
		}
	}
	//500.123
	for (int i = 0; i < strlen(array); i++)
	{
		if (array[i] == '.')
		{
			continue; //Go to next cycle of this 'for' loop
		}
		else if (hasDec == false) //Converts whole numbers w/out decimal
		{
			conversion += (static_cast<int>(array[i]) - 48) * pow(10, (strlen(array) - i-1));
		}
		else if (i < decPos)
		{
			conversion += (static_cast<int>(array[i]) - 48) * pow(10, (preDec-i));
		}
		else if (i > decPos)
		{
			conversion += (static_cast<int>(array[i]) - 48) * pow(10, (decPos - i));
		}
		loops++;
	}

	choice = conversion; //sets conversion of character array to integer needed to menu/user
	return false;

}

void introPrompt()
{
	cout << "========== WELCOME TO Team T.G.F.Y's 211 Group Project 1.0 ==========\n\n"
		<< "\nThis programs helps analyze mathematical representations of 'lines',\nEX: y = mx + b, by comparing them.\n\n\n"
		<< "=====================================================================\n\n"
		<< "Any time you see '...' the program is stalled. Press [ENTER] to continue!\n\n...";

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
				<< "               WELCOME TO THE MAIN MENU\n\n"
				<< "What would you like to do?\n\n"
				<< "1. Compare 2 Lines via Slope-Intercept (y = mx + b)\n"
				<< "2. Read 'sets_of_Lines.txt' for quadrilateral analysis\n"
				<< "3. Exit\n\n"
				<< "Your choice: ";

			cin.getline(selection, MAX_SIZE);
			if (cin.fail()) {
				cin.clear(); //clears error flags
				cerr << "\nINVALID INPUT! Enter ONLY what the prompt says!!! ...";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}
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

void opsComplete() { //Alerts user that the action they performed completed
	cout << "\n---------------------------------------------------------\n\n";
	cout << "Operation complete! Now returning to the previous menu ...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void printLineInfo(lineType obj1) {
	cout << "'m' value (slope)" << setw(11) << setfill('.') << "  " << obj1.get_m() << "\n'b' value (y-intercept)" << setw(5) << setfill('.') << "  " << obj1.get_y_intercept() << endl;
	cout << "Slop-Intercept Equation" << setw(5) << setfill('.') << "  " << obj1.get_eqnYMXB() << "\n\n";
	cout << "'A' value" << setw(19) << setfill('.') << "  " << obj1.get_a() << "\n'B' value" << setw(19) << setfill('.') << "  " << obj1.get_b() << "\n'C' value" << setw(19) << setfill('.') << "  " << obj1.get_c() << endl;
	cout << "Standard Form Equation" << setw(6) << setfill('.') << "  " << obj1.get_eqnABC() << "\n\n";
}

void printQuadInfo(quadType obj1)
{
	cout << "Is this shape a Parallelogram?";
	if (obj1.get_isParallelogram() == true) {
		cout << setw(3) << setfill('.') << " " << "YES\n";
	}
	else {
		cout << setw(3) << setfill('.') << " " << "NO\n";
	}
	cout << "Is this shape a Trapezoid?";
	if (obj1.get_isTrapezoid() == true) {
		cout << setw(7) << setfill('.') << " " << "YES\n";
	}
	else {
		cout << setw(7) << setfill('.') << " " << "NO\n";
	}
	cout << "Is this shape a Rectangle?";
	if (obj1.get_isRectangle() == true) {
		cout << setw(7) << setfill('.') << " " << "YES\n";
	}
	else {
		cout << setw(7) << setfill('.') << " " << "NO\n";
	}
	cout << "Is this shape a Rhombus?";
	if (obj1.get_isRhombus() == true) {
		cout << setw(9) << setfill('.') << " " << "YES\n";
	}
	else {
		cout << setw(9) << setfill('.') << " " << "NO\n";
	}
	cout << "Is this shape a Square?";
	if (obj1.get_isSquare() == true) {
		cout << setw(10) << setfill('.') << " " << "YES\n";
	}
	else {
		cout << setw(10) << setfill('.') << " " << "NO\n";
	}

	obj1.printIntersectionPoints();
}
