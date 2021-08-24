#include <iostream>

int main()
{
	// Variables for garnering the age of the person
	int year, age;

	// Program introduction
	std::cout << "Hello world\n\nWhat year were you born? ";

	// Gather user birth year and find the age
	std::cin >> year;
	
	age = 2021 - year;

	// Output of the age to the screen
	std::cout << "You are " << age << " year old.";

	return 0;
}