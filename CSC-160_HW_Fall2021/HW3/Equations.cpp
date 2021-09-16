#include "Equations.h"
#include <math.h>
#include <cmath>
#include <iomanip>

// Functions, constructors and deconstructors for for the GraphPoint class
// Constructor for an empty graph point
GraphPoint::GraphPoint()
{
	int_xValue = 0;
	int_yValue = 0;
}

// Constructor that builds the graph point from an X and Y value of type double
GraphPoint::GraphPoint(double arg_xValue, double arg_yValue)
{
}

// Destructor of the graph point
GraphPoint::~GraphPoint()
{
}

// Set the whole point with the values provided in X and Y pair arguments, respectively
void GraphPoint::SetPoint(double arg_xValue, double arg_yValue)
{
	int_xValue = arg_xValue;
	int_yValue = arg_yValue;
}

// Sets the parts of the point from a value that is assigned to either X or Y based on the character specified
void GraphPoint::SetPointPart(char arg_pointPart, double arg_value)
{
	switch (arg_pointPart)
	{
	case 'x':
		int_xValue = arg_value;
		break;

	case 'y':
		int_yValue = arg_value;
		break;
	}

}

// Functions, constructors, and deconstructors of QuadraticEquation class
// Constructor that takes in the double type inputs for the values in an euqation of form y=ax^2+bx+c
QuadraticEquation::QuadraticEquation(double arg_aValue, double arg_bValue, double arg_cValue)
{
	// Taking the input components of the equation and setting them to the internal components of the equation
	int_aValue = arg_aValue;
	int_bValue = arg_bValue;
	int_cValue = arg_cValue;

	// Creating a few points in the equation storage from the newly provided information
	points = new GraphPoint[5];
	points[0].SetPoint(-10.0, GetResult(-10.0));
	points[1].SetPoint(-1.0, GetResult(-1.0));
	points[2].SetPoint(0.0, GetResult(0.0));
	points[3].SetPoint(1.0, GetResult(-1.0));
	points[4].SetPoint(10.0, GetResult(-10.0));
}

// Constructor that takes two points to form the euqation in the form y=ax^2+bx+c
QuadraticEquation::QuadraticEquation(double arg_x1Value, double arg_y1Value, double arg_x2Value, double arg_y2Value)
{
	// New array created from the input points
	points = new GraphPoint[2];
	points[0].SetPoint(arg_x1Value, arg_y1Value);
	points[1].SetPoint(arg_x2Value, arg_y2Value);
}

// Constructor that is built from two GraphPoint type inputs that builds the function
QuadraticEquation::QuadraticEquation(GraphPoint arg_1Point, GraphPoint arg_2Point)
{
	// New array created from the input points
	points = new GraphPoint[2];
	points[0] = arg_1Point;
	points[1] = arg_2Point;
}

// Constructor that takes an array of GraphPoint objects to create an equation
QuadraticEquation::QuadraticEquation(GraphPoint* arg_points)
{
	points = arg_points;
}

// Destructor for the QuadraticEquation class
QuadraticEquation::~QuadraticEquation()
{
	//delete points;
}

// Function that provides the result from the x input in the euqation
double QuadraticEquation::GetResult(double arg_xValue)
{
	double result = int_aValue * std::pow(2.0, arg_xValue) + int_bValue * arg_xValue + int_cValue;
	return result;
}

// Return the different solutions for the equation based on the quadratic formula
std::complex<double>* QuadraticEquation::GetSolutions()
{
	std::complex<double> solution[2];

	// If the solutions for the equation have imaginary numbers
	if ((int_bValue * int_bValue - 4 * int_aValue * int_cValue) < 0)
	{
		// To work with the imaginaries and compute them correctly for output in the complex type, separating the real components and the imaginary components of the equation
		std::complex<double> realPart = -std::complex<double>(int_bValue) / (2.0 * std::complex<double>(int_aValue));
		std::complex<double> imaginaryPart = sqrt(std::pow(std::complex<double>(int_bValue), 2.0) - 4.0 * std::complex<double>(int_aValue) * std::complex<double>(int_cValue))/(2.0*std::complex<double>(int_aValue));
		
		// Outputting of the different solutions in a complex set
		solution[0] = (realPart + imaginaryPart);
		solution[1] = (realPart - imaginaryPart);
	}

	// If the solutions for the equation do not have imaginary numbers
	else
	{
		solution[0] = (-int_bValue + std::sqrt(std::pow(int_bValue, 2.0) - 4 * int_aValue * int_cValue)) / (2 * int_aValue);
		solution[1] = (-int_bValue - std::sqrt(std::pow(2.0, int_bValue) - 4 * int_aValue * int_cValue)) / (2 * int_aValue);
	}

	// Returning the set of solutions from the program
	return solution;
}

// Function that returns the graph point requested by the index of the points
GraphPoint QuadraticEquation::GetPoint(int arg_index)
{
	return GraphPoint();
}

// Get a display string for the equation
std::string QuadraticEquation::GetEquationDisplay()
{
	std::string result = "";

	result = "y=" + std::to_string(int_aValue) + "x^2";

	// Accounting for possible negative values of B
	if (int_bValue < 0)result += std::to_string(int_bValue) + "x";
	else result += "+" + std::to_string(int_bValue) + "x";

	// Accounting for possible negative values of C
	if (int_cValue < 0)result += std::to_string(int_cValue);
	else result += "+" + std::to_string(int_cValue);

	return result;
}

// Sets the equation after constructor builds the equation
void QuadraticEquation::SetEquation(double arg_aValue, double arg_bValue, double arg_cValue)
{
	int_aValue = arg_aValue;
	int_bValue = arg_bValue;
	int_cValue = arg_cValue;
}
