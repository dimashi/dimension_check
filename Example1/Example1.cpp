// Example1.cpp : Defines the entry point for the console application.
//

#include <math.h>
#include <iostream>

const double c = 3e8;	// light speed, meters / second

int main(int /*argc*/, char* argv[])
{
	double m = atof(argv[1]);	// mass, kg
	double E = m * pow(c, 2);	// energy, joules
	std::cout << "E = " << E;
	return 0;
}

