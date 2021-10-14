// Program that takes the input from a file, puts that in an array, and then sorts those numbers
#include <iostream>
#include <fstream>
#include <string>

int main()
{
	// Decleration of the points and other variables used in the program
	bool sortAscending = true, swapPerformed = true;
	int i = 0;
	unsigned int valuesCount = 0;
	double* fileValues = new double[1];
	double* holdValues = new double[1];
	std::ifstream inFile;
	std::ofstream outFile;
	std::string inFileName = "", outFileName = "", lineValue = "", userInput = "";
	
	// Gather the input from the user
	std::cout << "Mass Number Sorter\n";
	std::cout << "What is the name of the input file of numbers: ";
	std::cin >> inFileName;
	std::cout << "What is the name of the output file: ";
	std::cin >> outFileName;
	std::cout << "Sort ascending? (y/n):";
	std::cin >> userInput;
	if (userInput == "y") sortAscending = true;
	else sortAscending = false;

	// Gather the values from the file
	inFile.open(inFileName);
	if (inFile.is_open())
		while (std::getline(inFile, lineValue))
		{
			// Starts off the rotation through the line values with the incremenetation as we are simply counting in the values
			valuesCount++;

			// Initializes the array if this is the first time through the file
			if (valuesCount == 1)
			{
				fileValues = new double[valuesCount];
				holdValues = new double[valuesCount];
			}

			// Adds the value to the array of values
			else
			{
				delete[] fileValues;
				fileValues = new double[valuesCount];
				for (i = 0; i <= (valuesCount - 2); i++) fileValues[i] = holdValues[i];

				delete[] holdValues;
				holdValues = new double[valuesCount];
				for (i = 0; i <= (valuesCount - 2); i++) holdValues[i] = fileValues[i];
			}

			// Adds the value from the line to both the hold and the file values arrays
			fileValues[valuesCount - 1] = std::stod(lineValue);
			holdValues[valuesCount - 1] = std::stod(lineValue);
		}
	else std::cout << "ERROR: Cannot open file!!!";
	delete[] holdValues;

	// Sorting of the values that are in the file
	do
	{
		swapPerformed = false;
		for (i = 0; i <= (valuesCount - 2); i++)
		{
			if (fileValues[i] > fileValues[i + 1] && sortAscending)
			{
				swapPerformed = true;
				std::swap(fileValues[i], fileValues[i + 1]);
			}
			if (fileValues[i] < fileValues[i + 1] && !sortAscending)
			{
				swapPerformed = true;
				std::swap(fileValues[i + 1], fileValues[i]);
			}
		}
	} while (swapPerformed);

	// Outputting the values to the output file
	outFile.open(outFileName, std::ios::app);
	if (outFile.is_open())
		for (i = 0; i <= (valuesCount - 1); i++) outFile << fileValues[i] << "\n";
	outFile.close();

	// Graceful return of the program
	return 0;
}