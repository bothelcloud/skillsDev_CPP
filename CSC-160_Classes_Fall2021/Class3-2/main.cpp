#include <iostream>
#include <math.h>

int main()
{
	double value = 9;
	double resultRoot = 0;
	double resultPower = 0;  // If you are working with embedded numbers, there are going to be implicit interpretations of numbers there unless you are explicit with the numbers such as dots for float numbers or type casting
	resultPower = std::pow(value, -2);
	resultRoot = std::sqrt(value);

	std::cout << "\nResult Power = " << resultPower << "\n";
	std::cout << "Result Root = " << resultRoot << "\n";

	return 0;
}