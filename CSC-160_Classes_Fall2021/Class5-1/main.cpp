// Create a program that finds the slope of a line
#include <iostream>
#include <string>

int main()
{
	// Declaring the variables
	double x1 = 0, y1 = 0, x2 = 0, y2 = 0, m = 0;
	std::string userInput = "";

	// Introducing the program and gathering user input
	std::cout << "Line slope determining app\n\n";
	std::cout << "What is the X of point 1: ";
	std::cin >> userInput;
	x1 = std::stod(userInput);
	std::cout << "What is the y of point 1: ";
	std::cin >> userInput;
	y1 = std::stod(userInput);
	std::cout << "What is the X of point 2: ";
	std::cin >> userInput;
	x2 = std::stod(userInput);
	std::cout << "What is the y of point 2: ";
	std::cin >> userInput;
	y2 = std::stod(userInput);

	// Determining the slope of the line
	m = (y2 - y1) / (x2 - x1);

	// Outputting the results to the screen
	std::cout << "The slope of the line is " << m << ".";

	// Exiting the program gracefully
	return 0;
}