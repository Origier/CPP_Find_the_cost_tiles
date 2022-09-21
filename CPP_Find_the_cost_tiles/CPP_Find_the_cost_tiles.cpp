// C++ Find the cost of tiles for an area
// This program will calculate the cost for tiles over a certain area based on the user input

#include <iostream>
#include <math.h>

using namespace std;

int main() {
	double length;
	double width;
	double cost_per_unit;
	double total_area;  
	double total_cost;

	cout << "Please enter the width: ";
	cin >> width;

	cout << "Please enter the length: ";
	cin >> length;

	cout << "Please enter the cost per unit: ";
	cin >> cost_per_unit;
	
	total_area = width * length;
	total_cost = cost_per_unit * total_area;
	
	// Rounding to the nearest hundreths place
	total_cost = round(total_cost * 100) / 100;

	cout << "The total cost of tiles for this area is " << total_cost << endl;
	return 0;
}