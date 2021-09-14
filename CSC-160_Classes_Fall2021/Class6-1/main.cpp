// Objective: Gather 3 numbers from a user and average the numbers
// Warm-up for the evening class
#include <iostream>
#include <string>

int main()
{
	// Variable declerations
	double num1 = 0, num2 = 0, num3 = 0;
	std::string userInput = "";

	// Gathering the user input
	std::cout << "Number average calculator.\n\nPlease enter the first number: ";
	std::cin >> userInput;
	num1 = std::stod(userInput);

	std::cout << "Please enter the second number: ";
	std::cin >> userInput;
	num2 = std::stod(userInput);

	std::cout << "Please enter the third number: ";
	std::cin >> userInput;
	num3 = std::stod(userInput);

	// Outputting the average of the numbers
	std::cout << "\n\nThe average of your three numbers is " << double((num1 + num2 + num3) / 3.0) << ".\n";
}