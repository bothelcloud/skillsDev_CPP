#include <iostream>
#include <math.h>
#include <string>
#include <sstream>

// Defining a class for the functions to be input
class Function
{
public:
	// Constructors for the class objects
	Function();
	Function(const double& arg_x3Value, const double& arg_x2Value, const double& arg_x1value, const double& arg_constant);

	// Destructor for the class objects
	~Function();

	// Functions that get information from the object
	double GetSolution(const double& arg_xValue);
	std::string GetEquation();

	// Functions for the modification of the function
	void SetBase(const int& arg_basePosition, const double& arg_value);

private:
	double int_x3Value;
	double int_x2Value;
	double int_x1Value;
	double int_constant;
};

// Default constructor function
Function::Function()
{
	int_x3Value = 1.0;
	int_x2Value = 1.0;
	int_x1Value = 1.0;
	int_constant = 1.0;
}

// Constructor if I am inputting all the initial values
Function::Function(const double& arg_x3Value, const double& arg_x2Value, const double& arg_x1value, const double& arg_constant)
{
	int_x3Value = arg_x3Value;
	int_x2Value = arg_x2Value;
	int_x1Value = arg_x1value;
	int_constant = arg_constant;
}

// Function that supplies whatever the function results would be with the provided value of X
double Function::GetSolution(const double& arg_xValue)
{
	double solution = (int_x3Value * std::pow(arg_xValue, 3.0)) + (int_x2Value * std::pow(arg_xValue, 2.0)) + (int_x1Value * std::pow(arg_xValue, 1.0)) + int_constant;
	return solution;
}

// Function that gets the string for the eqation
std::string Function::GetEquation()
{
	std::ostringstream resultStream;
	std::string result;

	if (int_x3Value != 0)
	{
		resultStream << int_x3Value << "x^3";
	}
	if (int_x2Value != 0)
	{
		if (int_x2Value < 0)
		{
			resultStream << int_x2Value << "x^1";
		}
		else
		{
			resultStream << "+" << int_x2Value << "x^2";
		}
	}
	if (int_x1Value != 0)
	{
		if (int_x1Value < 0)
		{
			resultStream << int_x1Value << "x";
		}
		else
		{
			resultStream << "+" << int_x1Value << "x";
		}
	}
	if (int_constant != 0)
	{
		if (int_constant < 0)
		{
			resultStream << int_constant;
		}
		else
		{
			resultStream << "+" << int_constant;
		}
	}

	result = resultStream.str();

	return result;
}

// Modifies the base for a given power component in the function
void Function::SetBase(const int& arg_basePosition, const double& arg_value)
{
	switch (arg_basePosition)
	{
		case 3:
			int_x3Value = arg_value;
			break;
		case 2:
			int_x2Value = arg_value;
			break;
		case 1:
			int_x1Value = arg_value;
			break;
		case 0:
			int_x1Value = arg_value;
			break;
	}
}

// Destructor of the object
Function::~Function()
{
}

// Creating the main entry point for the program
int main()
{
	// Defining the equation
	Function equation((double)1.0, (double)0.0, (double)-3.0, (double)-4.0);
	double tolerance = 0.01, left = -1.0, right = 3.0, midpoint, leftBound = -1.0, rightBound = 3.0;
	int rotations = 0;
	std::string userInput = "";

	// Gathering the input from the user
	std::cout << "Finding solution by bisection program\n\nWhat is the x^3 base: ";
	std::cin >> userInput;
	equation.SetBase(3, std::stod(userInput));

	std::cout << "What is the x^2 base: ";
	std::cin >> userInput;
	equation.SetBase(2, std::stod(userInput));

	std::cout << "What is the x base: ";
	std::cin >> userInput;
	equation.SetBase(1, std::stod(userInput));

	std::cout << "What is the constant base: ";
	std::cin >> userInput;
	equation.SetBase(0, std::stod(userInput));

	std::cout << "What is the left bound: ";
	std::cin >> userInput;
	leftBound = std::stod(userInput);
	left = leftBound;

	std::cout << "What is the right bound: ";
	std::cin >> userInput;
	rightBound = std::stod(userInput);
	right = rightBound;

	std::cout << "What is the tolerance: ";
	std::cin >> userInput;
	tolerance = std::stod(userInput);

	// Perform actions here until the tolerance has been hit for differences for either side
	do {
		rotations++;
		midpoint = (left + right) / 2;
		if (equation.GetSolution(midpoint) == 0) break;
		if (equation.GetSolution(midpoint) < 0)
		{
			left = midpoint;
		}
		if (equation.GetSolution(midpoint) > 0)
		{
			right = midpoint;
		}
		if (std::abs(equation.GetSolution(midpoint)) < tolerance)
		{
			break;
		}
	} while (true);

	// Output of the information on the solution information to the screen
	std::cout << "\nFor the equation " << equation.GetEquation() << " on the interval [" << leftBound << "," << rightBound << "], there is a solution at f(" << midpoint << ") after " << rotations << " rotations.";
}