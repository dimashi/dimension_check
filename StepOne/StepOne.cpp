// StepOne.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <TSimpleType.h>

enum Dimension { mass, velocity, energy };

typedef TSimpleType<energy> Energy;
typedef TSimpleType<mass> Mass;
typedef TSimpleType<velocity> Velocity;

const Velocity c = 3e8;	// light speed, meters / second

int main(int /*argc*/, char* argv[])
{
	Mass m = atof(argv[1]);	// mass, kg
    Energy E;
	
    // energy cannot be assigned to mass, compile error - good
    //E = m;	
	
    // mass and light speed are of different types, also compile error.
    //m * c;			
    // ... but from physics point of view mass * velocity = momentum, so it should be legal.

	std::cout << "E = " << E;
	return 0;
}
