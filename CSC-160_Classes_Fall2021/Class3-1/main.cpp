// Warm-up program: Gather input from the user that is then ^2 for output

#include <iostream>
#include <cmath>

int main()
{
	// Declerations
	double input = 2;
	double power = 2;
	double result = 0;

	// Opening program and gathering user input
	std::cout << "Hello, and welcome to the squaring program!!!\n\n";

	// Gathering the user input to the program
	std::cout << "Please input a number to be squared: ";
	std::cin >> input;

	// Evaluating the result
	result = std::pow(input, power);

	std::cout << "Your input to a power is " << result << ". Thanks! :)\n\n";

	// Adding a return 0 for the successful completion of the program
	return 0;
}