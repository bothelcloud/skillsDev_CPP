#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

int main()
{
	std::string filename = "", lineValue = "";
	unsigned int valuesCount = 0, i = 0;
	double* fileValues = new double[1];
	double* holdValues = new double[1];
	double valuesAvg = 0.0, valuesDeviation = 0.0;
	std::ifstream inFile;
	std::ofstream outFile;

	// Setting the filename that is to be used for the program
	filename = "numbers.txt";

	// Open the into the program
	inFile.open(filename);

	// Read file contents into a dynamically sized array
	if (inFile.is_open())
		while (std::getline(inFile, lineValue))
		{
			valuesCount++;
			
			if (valuesCount == 1)
			{
				fileValues = new double[valuesCount];
				holdValues = new double[valuesCount];
			}

			else
			{
				delete[] fileValues;
				fileValues = new double[valuesCount];
				i = 0;
				while (i <= (valuesCount - 2)) fileValues[i] = holdValues[i++];

				delete[] holdValues;
				holdValues = new double[valuesCount];
				i = 0;
				while (i <= (valuesCount - 2)) holdValues[i] = fileValues[i++];
			}

			fileValues[valuesCount - 1] = std::stod(lineValue);
			holdValues[valuesCount - 1] = std::stod(lineValue);
		}
	else std::cout << "File didn't open correctly.";

	// Cleanup after brining in the file values
	inFile.close();
	delete[] holdValues;

	// Find the average of the values
	for (i = 0; i <= (valuesCount - 1); i++) valuesAvg += fileValues[i];
	valuesAvg /= valuesCount;
	std::cout << "Average for the numbers is " << valuesAvg << "\n";

	// Finding the standard deviation of the values
	for (i = 0; i <= (valuesCount - 1); i++) valuesDeviation += std::pow((fileValues[i] - valuesAvg), 2.0);
	valuesDeviation /= valuesCount;
	valuesDeviation = std::sqrt(valuesDeviation);
	std::cout << "Standard deviation for the numbers is " << valuesDeviation << "\n";

	// Outputting statistics information to the file
	outFile.open(filename, std::ios::app);
	if (outFile.is_open()) outFile << "\n\nMean (average) is " << valuesAvg << "\nStandard deviation is " << valuesDeviation;
	else std::cout << "File didn't open.";
	outFile.close();

	// Graceful exit of the program
	return 0;
}