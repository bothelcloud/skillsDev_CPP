#include <iostream>

// Main program entry point
int main()
{
	// Definition of the variables for the program
	double** equations;
	double solution[4];
	int count = 0;
	int i = 0, j = 0, k = 0;

	/**** Testing Case ****/
	count = 3;
	/**** Testing Case ****/

	// Build of the array for the equations
	equations = new double* [count];
	for (i = 0; i <= (count - 1); i++)
	{
		equations[i] = new double[4];
	}

	/**** Testing Case ****/
	// Sample equations
	equations[0][0] = 2.0;
	equations[0][1] = 5.0;
	equations[0][2] = 4.0;
	equations[0][3] = 9.0;
	
	equations[1][0] = -1.0;
	equations[1][1] = 1.0;
	equations[1][2] = 1.0;
	equations[1][3] = -2.0;
	
	equations[2][0] = 3.0;
	equations[2][1] = 4.0;
	equations[2][2] = -1.0;
	equations[2][3] = 3.0;

	/**** Testing Case ****/

	// Gaussian elimination processing
	
}