#include <iostream>

int main()
{
	int grade = 83;
	
	// Gathering the grade from the user
	std::cout << "Grade Letter Converter.\n\n";
	std::cout << "What was the numerical grade you received? ";
	std::cin >> grade;

	// Outputting the equivalent grade from the input
	std::cout << "The letter grade is ";
	if (grade > 89) std::cout << "A";
	if (grade <= 89 && grade >= 80) std::cout << "B";
	if (grade <= 79 && grade >= 70) std::cout << "C";
	if (grade <= 69 && grade >= 60) std::cout << "D";
	if (grade < 60) std::cout << "F";
	std::cout << ".\n\n";

}