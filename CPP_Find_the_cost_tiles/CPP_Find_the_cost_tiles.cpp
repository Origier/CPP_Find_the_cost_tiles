// C++ Find the cost of tiles for an area
// By: Aaron McDonald
// This program will calculate the cost for tiles over a certain area based on the user input

#define _USE_MATH_DEFINES

#include <iostream>
#include <math.h>
#include <cctype>


using namespace std;

// Calculates the area for a triangle
double calculate_triangle(double width, double height) {
	return ((width * height) / 2.0);
}

// Calculates the area for a circle
double calculate_circle(double radius) {
	return (M_PI * radius * radius);
}

// Calculates the area for a rectangle
double calculate_rectangle(double length, double width) {
	return length * width;
}

// Function to turn a string into all lower case characters
string lower_s(const string& s_in) {
	string lower_string = "";
	for (int i = 0; i < s_in.size(); i++) {
		lower_string.push_back(tolower(s_in[i]));
	}
	return lower_string;
}

int main() {
	// Variable Declaration
	double length;
	double width;
	double height;
	double radius;
	double square_feet_per_hour;
	double cost_per_hour;
	double cost_per_unit;
	double total_hours_cost;
	double work_hours;
	double total_area;  
	double total_cost;
	char leave;
	string room_shape;

	// Fetching all of the needed data
	cout << "Please enter the cost per hour for the labor: ";
	cin >> cost_per_hour;

	cout << "Please enter the average square feet per hour the labor can produce: ";
	cin >> square_feet_per_hour;

	cout << "Please enter the cost per unit of flooring: ";
	cin >> cost_per_unit;

	// Main loop to allow the user to make different calculations
	while (true) {
		// Getting the room shape from the user
		cout << "What is the shape of your room(Triangle, Rectangle, Circle, Exit): ";
		cin >> room_shape;

		room_shape = lower_s(room_shape); // Storing the fully lowercased version of user input

		// Calculating triangular area
		if (room_shape.compare("triangle") == 0) {
			cout << "Please enter the width: ";
			cin >> width;

			cout << "Please enter the height: ";
			cin >> height;

			total_area = calculate_triangle(width, height);
		}

		// Calculating rectangular area
		else if (room_shape.compare("rectangle") == 0) {
			cout << "Please enter the width: ";
			cin >> width;

			cout << "Please enter the length: ";
			cin >> length;
			total_area = calculate_rectangle(length, width);
		}

		// Calculating circular area
		else if (room_shape.compare("circle") == 0) {
			cout << "Please enter the radius: ";
			cin >> radius;
			total_area = calculate_circle(radius);
		}

		// Breaking out of the program loop if the user wants to exit
		else if (room_shape.compare("exit") == 0) {
			break;
		}

		// Skipping the ending calculations to ensure the user enters the correct data
		else {
			cout << "Please enter only one of the following options (Triangle, Rectangle, Circle, Exit)" << endl;
			continue;
		}

		// Calculating the cost based on the total area found
		total_cost = cost_per_unit * total_area;
		total_cost = round(total_cost * 100) / 100;

		cout << "The total cost for the tiles will be: " << total_cost << endl;
		
		// Calculates the number of hours that needs to be worked by the crew and the cost
		work_hours = ceil(total_area / square_feet_per_hour);
		total_hours_cost = work_hours * cost_per_hour;

		cout << "The total cost for the labor will be: " << total_hours_cost << endl;

		// Querying to do another calculation
		cout << "Would you like to continue(y/n): ";
		cin >> leave;
		leave = tolower(leave);
		if (leave == 'n') {
			break;
		}
	}
	return 0;
}