#include <iostream>

int main()
{
	// Declaring the variables that are used in the program
	float length, width, depth, volume;

	// Introducing the user to the program
	std::cout << "Hello, let's figure out the volume of a box.\n\n";
	std::cout << "What is your length? ";
	std::cin >> length;
	std::cout << "What is your width? ";
	std::cin >> width;
	std::cout << "What is your depth? ";
	std::cin >> depth;

	// Calculating the volume for the cube
	volume = length * width * depth;

	// Outputting the result to the user
	std::cout << "The volume of your box is " << volume << " cubic units.\n";
}