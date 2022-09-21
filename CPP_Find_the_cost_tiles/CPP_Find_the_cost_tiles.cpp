// C++ Find the cost of tiles for an area
// This program will calculate the cost for tiles over a certain area based on the user input

#include <iostream>

using namespace std;

int main() {
	double length;
	double width;
	double cost_per_unit;
	double total_area;

	cout << "Please enter the width: ";
	cin >> width;

	cout << "Please enter the length: ";
	cin >> length;

	cout << "Please enter the cost per unit: ";
	cin >> cost_per_unit;

	total_area = width * length;
	cout << "The total cost of tiles for this area is " << cost_per_unit * total_area << endl;
	return 0;
}