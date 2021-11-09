#include <iostream>

int main()
{
	// Declerations
	int r1 = 0, c1 = 0, r2 = 0, c2 = 0, i = 0, ii = 0, j = 0, k = 0;
	double sum = 0;
	double** matrix1;
	double** matrix2;
	double** matrix3;

	// Gathering user input for the array dimensions
	std::cout << "Matrix multiplication program\n\n";
	std::cout << "Enter the dimensions for the array in the form of rows (space) columns.\n";
	std::cout << "Enter the dimensions for matrix A: ";
	std::cin >> r1 >> c1;
	std::cout << "Enter the dimensions for matrix B: ";
	std::cin >> r2 >> c2;
	
	// Building the arrays in memory
	matrix1 = new double* [r1];
	for (i = 0; i <= (r1 - 1); i++)
	{
		matrix1[i] = new double[c1];
	}

	matrix2 = new double* [r2];
	for (i = 0; i <= (r2 - 1); i++)
	{
		matrix2[i] = new double[c2];
	}

	// Gathering array values from user
	for (i = 0; i <= (r1 - 1); i++)
	{
		for (ii = 0; ii <= (c1 - 1); ii++)
		{
			std::cout << "A[" << (i + 1) << "," << (ii + 1) << "]: ";
			std::cin >> matrix1[i][ii];
		}
	}

	for (i = 0; i <= (r2 - 1); i++)
	{
		for (ii = 0; ii <= (c2 - 1); ii++)
		{
			std::cout << "B[" << (i + 1) << "," << (ii + 1) << "]: ";
			std::cin >> matrix2[i][ii];
		}
	}

	// Building matrix that will hold results
	matrix3 = new double* [r1];
	for (i = 0; i <= (r1 - 1); i++)
	{
		matrix3[i] = new double[c2];
	}

	// Performing the matrix multiplication
	for (i = 0; i <= (r1 - 1); i++)
	{
		for (j = 0; j <= (c2 - 1); j++)
		{
			sum = (double)0.0;
			for (k = 0; k <= (c1 - 1); k++)
			{
				sum += matrix1[i][k] * matrix2[k][j];
			}
			matrix3[i][j] = sum;
		}
	}

	// Outputting the resulting matrix to the screen
	std::cout << "\nThe resulting matrix is as follows:\n";
	for (i = 0; i <= (r1-1); i++)
	{
		for (ii = 0; ii <= (c2 - 1); ii++)
		{
			std::cout << "\t" << matrix3[i][ii];
		}
		std::cout << "\n";
	}

	// Graceful exit of the program
	return 0;
}
