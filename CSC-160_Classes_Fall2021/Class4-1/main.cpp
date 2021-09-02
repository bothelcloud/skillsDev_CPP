// Warm up exercise for the class - program to ask for age and output it to the screen
#include <iostream>
#include <string>

int main()
{
	// Variables
	int userAge = 0;

	//Welcome and age collection
	std::cout << "Hello user!!!\n\nWhat is your age? ";
	std::cin >> userAge;

	// Outputting age to screen
	std::cout << "Nice, " << userAge << " years old is awesome! :)\n";
}