// This program should be able to return the m=0.2 for the points (3,7) and (-12,4)
#include <iostream>

int main()
{
	// Declaring the variables for use in my program
	double x1, y1, x2, y2, m;

	// Introducing the user to the program
	std::cout << "Hello, welcome to a program to find the slope of a line.\n\n";

	// Gathering the first point from the user
	std::cout << "What is the X1 coordinate: ";
	std::cin >> x1;
	std::cout << "What is the Y1 coordinate: ";
	std::cin >> y1;
	
	// Gathering the second point from the user
	std::cout << "What is the X2 coordinate: ";
	std::cin >> x2;
	std::cout << "What is the Y2 coordinate: ";
	std::cin >> y2;

	// Calculating the slope of the line
	m = (y2 - y1) / (x2 - x1);

	// Outputting the results for the user
	std::cout << "For the points (" << x1 << "," << y1 << ") and (" << x2 << "," << y2 << "), the slope is m=" << m << "\n\n";

	// Exiting the program
	return 0;
}