// This program is to help find the answers for quadratic functions
#include <iostream>
#include <math.h>
#include <iomanip>

int main()
{
	// Vairable decleration
	double a = 0, b = 0, c = 0;
	double solutionPositive, solutionNegative;
	char reload;
	bool testing = false;  // Added to allow in-line testing with values

	// Introducing the user to the program
	std::cout << "Welcome to the quadratic solver!!!\n\nFor this program, we are using the following format of equation:\nAx^2+Bx+C=0\n\n";

	// Application checking run
	if (testing)
	{
		a = 2.;
		b = 4.;
		c = -5.;
	}

	// If not testing, ask for the input from the user
	else
	{
		std::cout << "Enter the necessary information:\n";
		std::cout << "What is the A value for your equation? ";
		std::cin >> a;
		std::cout << "What is the B value for your equation? ";
		std::cin >> b;
		std::cout << "What is the C value for your equation? ";
		std::cin >> c;
	}
	
	// Ensuring that none of the equation components will result in a 0 in the denomenator of the equation
	if (2 * a == 0)
	{
		std::cout << "The value for A cannot be used in this program.\n";
		return 0;
	}

	// Checking the positive version of the quadratic equation
	solutionPositive = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);

	// Checking the negative version of the quadratic equation
	solutionNegative = (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);

	// Output the quadtratic formula resutls
	std::cout << "Positive operation: " << std::fixed << std::setprecision(3) << solutionPositive << "\n" 
		<< "Negative operation: " << solutionNegative << "\n";
	
	// Check to see if the user wants to run the program again
	std::cout << "Do you want to run the program again? (y/n) ";
	std::cin >> reload;
	if (reload == 'y') main();
	else return 0;
}