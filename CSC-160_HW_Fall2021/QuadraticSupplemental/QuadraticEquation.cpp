#include "QuadraticEquation.h"

QuadraticEquation::QuadraticEquation()
{

}

QuadraticEquation::QuadraticEquation(double y, double m, double b)
{

}

QuadraticEquation::QuadraticEquation(double x1, double y1, double x2, double y2)
{

}

QuadraticEquation::QuadraticEquation(EquationPoint* startingPoints)
{

}

std::string QuadraticEquation::ShowEquation()
{
	std::string output;

	output = ("y=" + prv_m + "x");

	return output;
}

QuadraticEquation::~QuadraticEquation()
{
}