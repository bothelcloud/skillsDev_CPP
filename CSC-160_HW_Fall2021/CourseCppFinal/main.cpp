#include <iostream>
#include <string>

// Main program entry point
int main()
{
	// Declerations for the variables used in the function
	int eqCount = 0, i = 0, j = 0, k = 0, ii = 0;
	double** eq;
	double* sol;
	double factor = 0, sum = 0;
	std::string userInput = "";

	// Gathering from the user the count of equations and variables
	std::cout << "What is the size of the array: ";
	std::cin >> userInput;
	eqCount = std::stod(userInput);

	// Building the array that will store the equations
	eq = new double* [eqCount];
	for (i = 0; i <= (eqCount - 1); i++)
	{
		eq[i] = new double[eqCount+1];
	}

	// Building the solutions array
	sol = new double[eqCount];

	// Gathering the array inputs from the user
	std::cout << "Input the values for the array to be assembled:\n";
	for (i = 0; i < eqCount; i++)
	{
		for (ii = 0; ii < (eqCount + 1); ii++)
		{
			std::cout << "a[" << (i + 1) << "][" << (ii + 1) << "]: ";
			std::cin >> userInput;
			eq[i][ii] = std::stod(userInput);
		}
	}
	std::cout << "\n";

	// Gaussian elimination
	for (i = 0; i < eqCount; i++)
	{
		for (j = i + 1; j < eqCount; j++)
		{
			factor = -eq[j][i] / eq[i][i];
			for (k = i; k < (eqCount + 1); k++)
			{
				eq[j][k] = eq[j][k] + factor * eq[i][k];
			}
		}
	}

	// Backwards substitution
	sol[(eqCount - 1)] = eq[(eqCount - 1)][eqCount] / eq[(eqCount - 1)][(eqCount - 1)];
	for (i = eqCount - 1; i >= 0; i--)
	{
		sum = 0;
		for (j = i + 1; j < eqCount; j++)
		{
			sum = sum + eq[i][j] * sol[j];
		}
		sol[i] = (eq[i][eqCount] - sum) / eq[i][i];
	}

	// Output of the solution to the user
	std::cout << "The solution for the system of euqations is ";
	for (i = 0; i < eqCount; i++)
	{
		std::cout << "x[" << (i + 1) << "]=" << sol[i];
		if ((i + 1) < eqCount)
		{
			std::cout << ", ";
		}
		else
		{
			std::cout << "\n";
		}
	}

	// Graceful exit of the program
	return 0;
}