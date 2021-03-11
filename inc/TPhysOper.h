#include <limits.h>

// Invalid dimension value
const int INVALID_DIMENSION = INT_MAX;

// This template works as compile time assert
template <bool> class TBool
{
};

// Dimensions for mecanics (time, distance, mass)
template <int  T, int D, int M> class TType
{
public:
	TType() 
    { 
        // If you get compile error here, somewhere in your code there is 
        // assignment, addition of subtraction of variables of different types.
        TBool<true>() = 
            TBool<  T != INVALID_DIMENSION && 
                    D != INVALID_DIMENSION && 
                    M != INVALID_DIMENSION>(); 
    }
	enum eTT { eT=T, eD=D, eM=M };
};

// Dimension arithmetic.
template <class T1, class T2> class TOper
{
	enum {m1 = T1::eT + T2::eT, m2 = T1::eD + T2::eD, m3 = T1::eM + T2::eM };
    enum {d1 = T1::eT - T2::eT, d2 = T1::eD - T2::eD, d3 = T1::eM - T2::eM };
	
    // for assignment, add and subtruct T1 must be the same as T2
    // if it is not, dimension will become INVALID_DIMENSION, and 
    // TBool will generate compile error.
    enum {s1 = T1::eT == T2::eT ? T1::eT : INVALID_DIMENSION, 
		  s2 = T1::eD == T2::eD ? T1::eD : INVALID_DIMENSION, 
		  s3 = T1::eM == T2::eM ? T1::eM : INVALID_DIMENSION,  
	};

    // for square root operation
    enum {sq1 = T1::eT == T2::eT ? T1::eT / 2 : INVALID_DIMENSION, 
		  sq2 = T1::eD == T2::eD ? T1::eD / 2 : INVALID_DIMENSION, 
		  sq3 = T1::eM == T2::eM ? T1::eM / 2 : INVALID_DIMENSION,  
	};
    // to do: add check for even numbers: sqrt should be applied only 
    // to dimension with even numbers.

    // for square root operation
    enum {e1 = T1::eT == T2::eT && T1::eT == 0 ? 0 : INVALID_DIMENSION, 
		  e2 = T1::eD == T2::eD && T1::eD == 0 ? 0 : INVALID_DIMENSION, 
		  e3 = T1::eM == T2::eM && T1::eM == 0 ? 0 : INVALID_DIMENSION,  
	};
    // to do: add check for even numbers: sqrt should be applied only 
    // to dimension with even numbers.

public:
	typedef TType<m1, m2, m3> multiply;
	typedef TType<s1, s2, s3> multiplyScalar;
	typedef TType<d1, d2, d3> divide;
	typedef TType<s1, s2, s3> divideScalar;
	typedef TType<s1, s2, s3> assign;
	typedef TType<s1, s2, s3> add;
	typedef TType<s1, s2, s3> subtract;
    
    // additional functions added to support Example2
    typedef TType<sq1, sq2, sq3>    sqrt;
    typedef TType<e1, e2, e3>       exp;
    typedef TType<s1, s2, s3>       abs;
    typedef TType<s1, s2, s3>       conj;

};

