// Example2.cpp : Neutron reflectivity

#include <complex>
#include <iostream>

using namespace std;

#define CHECK_DIMENSION

#ifdef CHECK_DIMENSION

#include <TPhysOper.h>
#include <TParamType.h>

typedef TParamType<TType< 0, 1, 0>, complex<double> >   Distance;
typedef TParamType<TType< 0, 2, 0>, complex<double> >   Area;
typedef TParamType<TType< 0, 0, 1>, complex<double> >   Mass;
typedef TParamType<TType<-1, 1, 0>, complex<double> >   Velocity;
typedef TParamType<TType<-2, 2, 1>, complex<double> >   Energy;
typedef TParamType<TType<0, -1, 0>, complex<double> >   WaveVector;  // Distance^-1
typedef TParamType<TType<0, -3, 0>, complex<double> >   Density;     // particles / Distance^3
typedef TParamType<TType<0, 0, 0>, complex<double> >    Scalar;
typedef const TParamType<TType<-1, 2, 1>, complex<double> >   PlankConstant;

#else  // CHECK_DIMENSION

typedef complex<double>   Distance;
typedef complex<double>   Area;
typedef complex<double>   Mass;
typedef complex<double>   Velocity;
typedef complex<double>   Energy;
typedef complex<double>   WaveVector;  // Distance^-1
typedef complex<double>   Density; // particles / Distance^3
typedef complex<double>   Scalar;
typedef const complex<double> PlankConstant;

#endif // CHECK_DIMENSION

// Math constants
const Scalar   Pi2 = 2 * 3.1415926;
const Scalar i = complex<double>(0, 1);

// Physics constants
PlankConstant h = 6.626e-34;    // Planck constant
const Mass m = 1e-30;           // neutron mass


// Potential describing matter with which neutron interacts
Energy GetPotential(const Density& N, const Distance& b, const Area& sigma, const Velocity& v)
{
    return Pi2 * h * h / m * N * b - 
        i / Scalar(2.0) * N * h * sigma * v;
}

WaveVector GetWaveVector(const Energy& U, const WaveVector& k0)
{
    return sqrt(k0 * k0 - Scalar(2.0) * m * U / h / h);
}

int main(int argc, char* argv[])
{
	// Neutron characteristics
    const WaveVector    k0 = 1e1;           // neutron wave vector in vacuum
    const Velocity      v0 = 4e2;           // neutron velocity

    // Sample structure: two medias, one boundary
    // 
    //        | 
    // vacuum | media two. 
    //        |
    
    // Characteristics of the sample
    // Media one - vacuum
    const Density   N1 = 0;                 // atom density (vacuum)
    const Distance  b1 = 0;                 // length of coherent scattering (vacuum)
    const Area      sigma1 = 0;             // non-elastic cross-section (vacuum)
    
    // Media two - something different from vacuum
    const Density   N2 = 6e22;              // atom density
    const Distance  b2 = 1e-14;             // length of coherent scattering
    const Area      sigma2 = 1e-20;         // non-elastic cross-section

    Energy U1 = GetPotential(N1, b1, sigma1, v0);
    Energy U2 = GetPotential(N2, b2, sigma2, v0);
    
    // neutron wave vector in vacuum (media one) and in media two
    WaveVector k1 = GetWaveVector(U1, k0);
    WaveVector k2 = GetWaveVector(U2, k0);

    Distance z1 = 0.0;  // one boundary, z1 == z2
    Distance z2 = 0.0;  
    
    // A and B are wave function of the neutron.
    // A is amplitude of penetrating wave, B is amplitute of reflected wave
    // In the second media there is only one wave - penetrating.
    Scalar A1 = 1;
    Scalar B1 = 0;
    
    Scalar A2 = Scalar(0.5) / exp(i * k2 * z2) * 
        (A1 * exp(i * k1 * z2) * (Scalar(1) + k1 / k2) +
         B1 / exp (i * k1 * z2) * (Scalar(1) - k1 /k2));

    Scalar B2 = Scalar(0.5) * exp(i * k2 * z2) * 
        (A1 * exp(i * k1 * z2) * (Scalar(1) - k1 / k2) +
         B1 / exp (i * k1 * z2) * (Scalar(1) + k1 /k2));

    // Reflectivity is ratio of reflected wave to penetrating wave.
    Scalar R = ( abs(B2) * abs(B2)) / (abs(A2) * abs(A2));

    cout << "Reflectivity " << R << endl;

    return 0;
}
