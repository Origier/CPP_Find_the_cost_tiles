// C++ Find the cost of tiles for an area
// By: Aaron McDonald
// This program will calculate the cost for tiles over a certain area based on the user input

#define _USE_MATH_DEFINES

#include <iostream>
#include <math.h>
#include <cctype>
#include <string>

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

// Gets a double value from the user while ensuring that the data is valid
double get_data() {
	string valid_characters = "0123456789."; // Declaring all of the valid characters that are acceptable input
	string tester_string; // used for validating data
	bool has_decimal; // used for ensuring there is only one decimal 
	bool all_num;
	while (true) {
		cin >> tester_string;
		all_num = true;
		has_decimal = false;
		// Looping over the string and testing to ensure that each charater is a part of the valid characters set
		for (int i = 0; i < tester_string.size(); i++) {
			if (valid_characters.find(tester_string[i]) == string::npos) {
				cout << "Please enter only numbers or a period, no characters: ";
				all_num = false;
				break;
			}

			// Ensuring that the string only contains one decimal point
			else if (tester_string[i] == '.') {
				if (has_decimal) {
					all_num = false;
					cout << "Please only enter one decimal point: ";
					break;
				}
				has_decimal = true;
			}
		}

		// Returning the string made double assuming all requirements are met
		if (all_num) {
			return stod(tester_string);
		}
		else {
			continue;
		}
		
	}
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
	cost_per_hour = get_data();

	cout << "Please enter the average square feet per hour the labor can produce: ";
	square_feet_per_hour = get_data();

	cout << "Please enter the cost per unit of flooring: ";
	cost_per_unit = get_data();

	// Main loop to allow the user to make different calculations
	while (true) {
		// Getting the room shape from the user
		cout << "What is the shape of your room(Triangle, Rectangle, Circle, Exit): ";
		cin >> room_shape;

		room_shape = lower_s(room_shape); // Storing the fully lowercased version of user input

		// Calculating triangular area
		if (room_shape.compare("triangle") == 0) {
			cout << "Please enter the width: ";
			width = get_data();

			cout << "Please enter the height: ";
			height = get_data();

			total_area = calculate_triangle(width, height);
		}

		// Calculating rectangular area
		else if (room_shape.compare("rectangle") == 0) {
			cout << "Please enter the width: ";
			width = get_data();

			cout << "Please enter the length: ";
			length = get_data();
			total_area = calculate_rectangle(length, width);
		}

		// Calculating circular area
		else if (room_shape.compare("circle") == 0) {
			cout << "Please enter the radius: ";
			radius = get_data();
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