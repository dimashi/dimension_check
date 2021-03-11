// StepTwo.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <TPhysType.h>

// typedef TPhysType<0, 0, 0, double> Scalar;
// Fundamental types
typedef TPhysType<1, 0, 0> Time;
typedef TPhysType<0, 1, 0> Distance;
typedef TPhysType<0, 0, 1> Mass;
typedef TPhysType<-1, 1, 0> Velocity;
typedef TPhysType<-2, 2, 1> Energy;
typedef TPhysType<-1, 1, 1> Momentum;

const Velocity c = 3e8;	// light speed, meters / second

int main(int /*argc*/, char* argv[])
{
	Mass m = atof(argv[1]);	// mass, kg
    Energy E;

    // energy cannot be assigned to mass, compile error - good
    //E = m;	
	
    // from physics point of view mass * velocity = momentum, so it should be legal, no compile error.
    m * c;	
    
    // Addition operator should check for type compatibility, compile error
    // m * c + c;
    
    // mass * velocity = momentum, not energy, compile error
    // E = m * c;

    // ok
    E = m * c * c;

	std::cout << "E = " << E;
	return 0;
}

