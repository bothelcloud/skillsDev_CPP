// Program that works with cubic fuctions
#include <iostream>
#include <math.h>

// Function that represents the equation to call over and over again
double Equation(double aValue, double bValue, double cValue, double dValue, double xValue)
{
	double result = aValue * std::pow(xValue, 3.0) + bValue * std::pow(xValue, 2.0) + cValue * xValue + dValue;
	return result;
}

int main()
{
	// Declerations for the program
	double aEq = 0, bEq = 0, cEq = 0, dEq = 0;
	double limitLeft = 0, limitRight = 0;
	double precision = 0, i = 0;
	double min = 0, max = 0, minXValue = 0, maxXValue = 0;

	// Welcoming the user and gathering the inputs
	std::cout << "Welcome to cubic equation max and min identifier!\n\n";

	std::cout << "What is the A term in the function: ";
	std::cin >> aEq;
	std::cout << "What is the B term in the function: ";
	std::cin >> bEq;
	std::cout << "What is the C term in the function: ";
	std::cin >> cEq;
	std::cout << "What is the D term in the function: ";
	std::cin >> dEq;

	std::cout << "What is the left limit: ";
	std::cin >> limitLeft;
	std::cout << "What is the right limit: ";
	std::cin >> limitRight;

	std::cout << "To what precision do you want to evaluate: ";
	std::cin >> precision;

	// Setting initial min and max from the equation and initial X value
	min = Equation(aEq, bEq, cEq, dEq, limitLeft);
	max = Equation(aEq, bEq, cEq, dEq, limitRight);
	minXValue = limitLeft;
	maxXValue = limitRight;
	i = limitRight;

	// Finding the min and max values for the equation
	do
	{
		if (Equation(aEq, bEq, cEq, dEq, i) > max)
		{
			max = Equation(aEq, bEq, cEq, dEq, i);
			maxXValue = i;

		}
		
		if (Equation(aEq, bEq, cEq, dEq, i) < min)
		{
			min = Equation(aEq, bEq, cEq, dEq, i);
			minXValue = i;
		}

		i -= precision;
		
	} while (i >= limitLeft);

	// Outputting the equation that was created when the user input their values
	std::cout << "\nThe equation you entered is f(x)=" << aEq << "x^3";
	if (bEq < 0) std::cout << bEq << "x^2";
	else std::cout << "+" << bEq << "x^2";
	if (cEq < 0) std::cout << cEq << "x";
	else std::cout << "+" << cEq << "x";
	if (dEq < 0) std::cout << dEq << "\n";
	else std::cout << "+" << dEq << "\n";

	// Outputting the min and max values for the equation that was input by the user
	std::cout << "The function results in f(" << maxXValue << ")=" << max << " as maximum and f(" << minXValue << ")=" << min << " as minimum within the limit [" << limitLeft << "," << limitRight << "].\n";

	// Graceful exiting the program
	return 0;
}