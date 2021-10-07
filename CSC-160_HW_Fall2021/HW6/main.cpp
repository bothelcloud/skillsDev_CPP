// Program that utilizes the bisection method to find roots of mathematical functions
#include <iostream>
#include <string>
#include <math.h>

// Object that handles the equation entered into the program
class CubicFunction
{
public:
	// Initiators for the class
	CubicFunction(double value3rdPower, double value2ndPower, double value1stPower, double value0thPower);

	// Functions for the objects
	std::string FunctionDisplay();
	double FunctionResult(double xValue);

private:
	double value3rdPower = 0;
	double value2ndPower = 0;
	double value1stPower = 0;
	double value0thPower = 0;
};

CubicFunction::CubicFunction(double parameter3rdPower, double parameter2ndPower, double parameter1stPower, double parameter0thPower)
{
	value3rdPower = parameter3rdPower;
	value2ndPower = parameter2ndPower;
	value1stPower = parameter1stPower;
	value0thPower = parameter0thPower;
}

// Function that produces the string value for display of the equation
std::string CubicFunction::FunctionDisplay()
{
	// Starting out the string with the leading value and the third power
	std::string result = "";

	// Putting the 3rd power to the equation
	if (value3rdPower != 0) result += std::to_string(value3rdPower) + "x^3";
	else if (value3rdPower == 1) result += "+x^3";

	// Putting the 2nd power to the equation
	if (value2ndPower < 0) result += std::to_string(value2ndPower) + "x^2";
	else if (value2ndPower == 1) result += "+x^2";
	else if (value2ndPower > 0) result += "+" + std::to_string(value2ndPower) + "x^2";

	// Putting the 1st power to the equation
	if (value1stPower < 0) result += std::to_string(value1stPower) + "x";
	else if (value1stPower > 0) result += "+" + std::to_string(value1stPower) + "x";

	// Putting the 0th power to the equation
	if (value0thPower < 0) result += std::to_string(value0thPower);
	else if (value0thPower > 0) result += "+" + std::to_string(value0thPower);
	
	return result;
}

// Function that produces the result from the equation result based on the provided value
double CubicFunction::FunctionResult(double xValue)
{
	return double(value3rdPower * std::pow(xValue, (double)3.0) + value2ndPower * std::pow(xValue, (double)2.0) + value1stPower * xValue + value0thPower);
}

int main()
{
	// Variable declerations for the program
	unsigned int iterations = 0;
	double leftResult = 0, midResult = 0, rightResult = 0;
	double input3rdPower = 0.0, input2ndPower = 0.0, input1stPower = 0.0, input0thPower = 0.0;
	double tolerance = 0.0, intervalLeft = 0.0, intervalRight = 0.0, result = 0.0;
	double originalLeft = 0.0, originalRight = 0.0;
	std::string userInput = "";

	// Introducing the user to the application
	std::cout << "App for finding roots on an interval (Bisection method)\n\n";

	std::cout << "What would you like to do? Enter \"begin\" to continue with inputs or type \"debug\" to start a debug run.\nCommand: ";
	std::cin >> userInput;

	// Enter the debug mode for the app
	if (userInput == "debug")
	{
		input3rdPower = 1.0;
		input2ndPower = 0.0;
		input1stPower = -3.0;
		input0thPower = 4.0;

		intervalLeft = -4.0;
		intervalRight = -1.0;
		tolerance = 0.1;
	}

	// Begin gathering the user input
	else if (userInput == "begin")
	{
		std::cout << "x^3 value: ";
		std::cin >> userInput;
		input3rdPower = std::stod(userInput);

		std::cout << "x^2 value: ";
		std::cin >> userInput;
		input2ndPower = std::stod(userInput);

		std::cout << "x value: ";
		std::cin >> userInput;
		input1stPower = std::stod(userInput);

		std::cout << "static value: ";
		std::cin >> userInput;
		input0thPower = std::stod(userInput);

		std::cout << "Left interval value: ";
		std::cin >> userInput;
		intervalLeft = std::stod(userInput);

		std::cout << "Right interval value: ";
		std::cin >> userInput;
		intervalRight = std::stod(userInput);

		std::cout << "Tolerance value: ";
		std::cin >> userInput;
		tolerance = std::stod(userInput);
	}

	// Setting up the equation for the app run
	CubicFunction equation(input3rdPower, input2ndPower, input1stPower, input0thPower);

	// Setting display variables for the originals
	originalLeft = intervalLeft;
	originalRight = intervalRight;

	// Perform the iterations until the roots are found in the interval
	do
	{
		// Counting the iteration
		iterations++;

		// Getting the interval values and the midpoint
		leftResult = equation.FunctionResult(intervalLeft);
		midResult = equation.FunctionResult((intervalLeft + intervalRight) / 2);
		rightResult = equation.FunctionResult(intervalRight);

		// Testing to see if an exact 0 has been found
		if (midResult == 0) break;

		// If mid result is less than the tolerance
		if (std::abs(midResult) < tolerance)
		{
			result = (intervalLeft + intervalRight) / 2;
			break;
		}

		// Checking for a right adjustment
		if (midResult < 0) intervalLeft = (intervalLeft + intervalRight) / 2;

		// Checking for a left adjustment
		if (midResult > 0) intervalRight = (intervalLeft + intervalRight) / 2;

	} while (true);

	// Output of the result to the screen
	std::cout << "\nThe root for the equation " << equation.FunctionDisplay() << " is at x=" << result << " on the interval [" << originalLeft << "," << originalRight << "] and found in " << iterations << " iterations\n";

	// Graceful exit of the program
	return 0;
}