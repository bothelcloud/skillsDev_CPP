// Create a program that takes two points and figures the distance between the two points
#include <iostream>
#include <math.h>

int main()
{
	// Declaration of variables for use
	double x1, y1, x2, y2, distance;

	// Introduction and gathering user input
	std::cout << "Welcome to the point distance calculator!!!\n\n";
	std::cout << "What is the value for X1: ";
	std::cin >> x1;
	std::cout << "What is the value for Y1: ";
	std::cin >> y1;
	std::cout << "What is the value for X2: ";
	std::cin >> x2;
	std::cout << "What is the value for y2: ";
	std::cin >> y2;

	// Calculation of distance
	distance = std::sqrt(pow(y2 - y1, 2) + pow(x2 - x1, 2));

	// Output of the result
	std::cout << "The distance between your two points is " << distance << ". Thanks for using this calculator!:)\n";

	// Exiting the program successfully
	return 0;
}