#include <iostream>

namespace one 
{
#include <TSimpleOper.h>
#include <TParamType.h>
}

namespace two 
{
#include <TPhysOper.h>
#include <TParamType.h>
}

typedef one::TParamType<one::TType<1>, double> Distance2;

typedef two::TParamType<two::TType< 1, 0, 0>, double>   Time;
typedef two::TParamType<two::TType< 0, 1, 0>, double>   Distance;
typedef two::TParamType<two::TType< 0, 0, 1>, double>   Mass;
typedef two::TParamType<two::TType<-1, 1, 0>, double>  Velocity;
typedef two::TParamType<two::TType<-2, 2, 1>, double>  Energy;
typedef two::TParamType<two::TType<-1, 1, 1>, double>  Momentum;

const Velocity c = 3e8;	// light speed, meters / second

int main(int /*argc*/, char* argv[])
{
    Mass m = atof(argv[1]);	// mass, kg
    Energy E;

    // Energy cannot be assigned to mass, compile error - good
    // E = m;	
	
    // from physics point of view mass * velocity = momentum, 
    // so it should be legal, no compile error.
    m * c;			

    // Addition operator should check for type compatibility, compile error in VC6.0, 
    // no compile error in BC5.5
    // m * c + c;			
    
    // mass * velocity = momentum, not energy, compile error
    // Momentum E2 = m * c;// * 2.0;

    // ok
    //E = m * c * c * 2.0;

	std::cout << "E = " << E;
    
    return 0;
}
