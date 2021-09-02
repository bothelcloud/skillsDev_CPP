// Warm up exercise for the class - program to ask for age and see if old enough to get a drivers license
#include <iostream>
#include <string>

int main()
{
	// Variables
	int userAge = 0;
	int ageDiff = 0;

	//Welcome and age collection
	std::cout << "Hello user!!!\n\nWhat is your age? ";
	std::cin >> userAge;

	// Determining if the age is appropriate for a license
	if (userAge >= 16)
	{
		std::cout << "You are old enough to get a driver's licensee!";
	}
	else
	{
		ageDiff = 16 - userAge;
		std::cout << "You have " << ageDiff << " years left before you are able to drive.";
	}

	// Returning a normal completion for the program
	return 0;
}