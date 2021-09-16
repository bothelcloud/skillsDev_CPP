// Program that provides solutions to three cases of quadratic equations
// Case 1) equation with two solutions for 0
// Case 2) equation with one solution for 0
// Case 3) equation with imaginary solutions for 0

#include <iostream>
#include <string>
#include "Equations.h"

int main()
{
	// Decleration of the variables that will be used for this program
	std::string userInput = "";
	int index = 0;
	char valueChar = 65;
	double values[3] = { 0.0,0.0,0.0 };

	// Introducing the user to the program
	std::cout << "Welcome to the quadratic solver!\n\n";

	// Gathering the equation values from the user
	do
	{
		std::cout << "What is the " << valueChar << " value for the equation : ";
		std::cin >> userInput;

		if (userInput == "restart") main();
		else if (userInput == "exit") return 0;
		else values[index] = std::stod(userInput);

		valueChar++;
		index++;
	} while (valueChar <= 67);

	// Building the equation object
	QuadraticEquation equation(values[0], values[1], values[2]);

	// Outputting the resultant equation
	std::cout << "\nThe resultant equation is " << equation.GetEquationDisplay() << " from inputs.\n";

	// Outputting the solutions to the screen
	if (std::imag((equation.GetSolutions())[0]) != 0 || std::imag((equation.GetSolutions())[0]) != 0)
	{
		std::cout << "The solutison are x=";
		if (std::imag((equation.GetSolutions())[0]) < 0)
			std::cout << std::real((equation.GetSolutions())[0]) << std::imag((equation.GetSolutions())[0]) << "i";
		else std::cout << std::real((equation.GetSolutions())[0]) << "+" << std::imag((equation.GetSolutions())[0]) << "i";

		std::cout << ",";

		if (std::imag((equation.GetSolutions())[1]) < 0)
			std::cout << std::real((equation.GetSolutions())[1]) << std::imag((equation.GetSolutions())[1]) << "i";
		else std::cout << std::real((equation.GetSolutions())[1]) << "+" << std::imag((equation.GetSolutions())[1]) << "i";

		std::cout << " for the equation.\n";
	}

	// What to display if there is only one solution
	else if (std::real((equation.GetSolutions())[0]) == std::real((equation.GetSolutions())[1]))
	{
		std::cout << "The solutions are x=" << std::real((equation.GetSolutions())[0]) << " for the equation.\n";
	}

	// All other solutions for quadratics
	else
	{
		std::cout << "The solutions are x=" << std::real((equation.GetSolutions())[0]) << ", " << std::real((equation.GetSolutions())[1]) << " for the equation.\n";
	}

	// Graceful return of the program
	return 0;
}