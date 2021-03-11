template <int T> struct TType
{
	enum eTT { eT1 = T};
};


typedef TType<0> InvalidType;


template <typename T1, typename T2> struct TOper
{
	enum {s1 = T1::eT1};

	typedef InvalidType multiply;
	typedef TType<s1> multiplyScalar;
	typedef InvalidType divide;
	typedef TType<s1> divideScalar;
	typedef TType<s1> assign;
	typedef TType<s1> add;
	typedef TType<s1> subtract;
    
    // additional functions added to fix consequences of adding support for Example2 :)
    typedef TType<s1> sqrt;
	typedef TType<s1> exp;
    typedef TType<s1> conj;
};


