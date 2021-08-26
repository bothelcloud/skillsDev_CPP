// Program for averaging 3 numbers
#include <iostream>


int main()
{
	// Went with the 3 numbers as the assumption of whole
	int val1, val2, val3;

	// Went with a float as we might not get completely whole numbers
	float avg;

	// Gathering the input from the user
	std::cout << "Hello, we are going to average 3 numbers.\n\n";
	std::cout << "What's the first number? ";
	std::cin >> val1;
	std::cout << "What's the second number? ";
	std::cin >> val2;
	std::cout << "What's the third number? ";
	std::cin >> val3;

	// Performing the calculation of the average
	avg = (float(val1) + float(val2) + float(val3)) / 3;

	// Outputting the value to the screen
	std::cout << "The average of the three numbers is " << avg << ".\n\nHave a great day!";


	// Returning completed successfully
	return 0;
}