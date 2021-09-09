#pragma once
#include <string>

// Class for the use of a quadratic equation as a single object
class QuadraticEquation
{
public:
	// Constructors
	QuadraticEquation();
	QuadraticEquation(double y, double m, double b);
	QuadraticEquation(double x1, double y1, double x2, double y2);
	QuadraticEquation(EquationPoint* startingPoints);

	// Public functions
	std::string ShowEquation();

	// Public values
	const double* m = &prv_m;
	const double* b = &prv_b;

	// Deconstructor
	~QuadraticEquation();

private:
	EquationPoint* points;
	double prv_m, prv_b;
};

// More advanced point storage capability in code
class EquationPoint
{
public:
	EquationPoint();
	EquationPoint(double x, double y);

private:
	double x, y;
	std::string comment;
};