// Program that finds the value of pi to a tolerance between two values for its iteration
#include <iostream>
#include <math.h>

int main()
{
	// Declearation of variables for this function
	double piValue = 0.0, oldPiValue = piValue;
	unsigned long int denominator = 1;
	float tolerance = 0.0;
	unsigned int iterations = 0;
	short int multiplier = 1;

	// Introduction and gather the tolerance from the user
	std::cout << "Pi calculator!\nWhat is the tolerance you want to find pi to: ";
	std::cin >> tolerance;

	// Perform the iterations through the equation to the result
	do
	{
		iterations++;
		oldPiValue = piValue;
		piValue += ((double)multiplier * (4 / (double)denominator));
		denominator += 2;
		multiplier *= -1;
	} while (std::abs(piValue - oldPiValue) >= (double)tolerance);

	// Output result to user
	std::cout << "The pi value is " << piValue << " to a tolerance of less than " << tolerance << " and took " << iterations << ".\n";

	// Graceful exit of the program
	return 0;
}