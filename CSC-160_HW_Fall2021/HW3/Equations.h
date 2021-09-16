#pragma once
#include <string>
#include <complex>

// Class that represents points on a graph 
class GraphPoint
{
public:
	// External direct references to internal variables of the point
	const double* X = &int_xValue;
	const double* Y = &int_yValue;

	// Constructors for the class
	GraphPoint();
	GraphPoint(double arg_xValue, double arg_yValue);

	// Destructor for the class
	~GraphPoint();

	// Data retrieval functions for the class

	// Data Modification functions for the class
	void SetPoint(double arg_xValue, double arg_yValue);
	void SetPointPart(char arg_pointPart, double arg_value);

private:
	double int_xValue = 0;
	double int_yValue = 0;
};

// Class that is used for subsequent objects that are representative of quadratic equations
class QuadraticEquation
{
public:
	// External direct references to variables within the equation
	const std::string* Equation = &int_equation;
	const double* A = &int_aValue;
	const double* B = &int_bValue;
	const double* C = &int_cValue;

	// Constructors for the objects
	QuadraticEquation(double arg_aValue, double arg_bValue, double arg_cValue);
	QuadraticEquation(double arg_x1Value, double arg_y1Value, double arg_x2Value, double arg_y2Value);
	QuadraticEquation(GraphPoint arg_1Point, GraphPoint arg_2Point);
	QuadraticEquation(GraphPoint *arg_points);

	// Destructor for the objects
	~QuadraticEquation();

	// Functions that pull different information from the equation
	double GetResult(double arg_xValue);
	std::complex<double> *GetSolutions();
	GraphPoint GetPoint(int arg_index);
	std::string GetEquationDisplay();

	// Functions that modify the equation
	void SetEquation(double arg_aValue, double arg_bValue, double arg_cValue);
	
	// Functions that modify the points
	void AddPoint(double arg_xValue, double arg_yValue);
	void AddPoint(GraphPoint arg_point);
	
private:
	// Components that make up the equation
	double int_aValue = 0.0;
	double int_bValue = 0.0;
	double int_cValue = 0.0;
	GraphPoint *points;

	// Presentation variables for the equation
	std::string int_equation = "";
};