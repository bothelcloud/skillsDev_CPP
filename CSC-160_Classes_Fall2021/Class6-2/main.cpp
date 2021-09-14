// Creating a program that loops around to average as many numbers as you want to input
#include <iostream>
#include <string>

int main()
{
	// Defining the variables for use in the program
	int i = 0;
	double run = 0, avg = 0;
	std::string userInput = "";

	// Loop that gathers from the user the value that they then want to have averaged
	while (0==0)
	{
		std::cout << "Input number to use as part of the average: ";
		std::cin >> userInput;

		if (userInput == "exit") break;
		else if (userInput == "done") break;
		else if (userInput == "restart") break;
		else
		{
			run += std::stod(userInput);
			i++;
		}
	}

	if (userInput == "done") std::cout << "\n\nThe average of the numbers is " << double(run / i) << ".";
	if (userInput == "restart") main();

	return 0;
}