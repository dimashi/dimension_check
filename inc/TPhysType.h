#ifndef TPhysType_h
#define TPhysType_h

template <int T, int D, int M> class TPhysType
{
public:
	enum { eT = T, eD=D, eM=M };
    typedef TPhysType type;

	TPhysType() : m_dt(0) {}
	TPhysType(double dt) : m_dt(dt) {}

	TPhysType& operator = (const TPhysType& o)
	{
		m_dt = o.m_dt;
		return *this;
	}

	TPhysType operator + (const TPhysType& o) const
	{
		return TPhysType(m_dt + o.m_dt);
	}

	TPhysType operator - (const TPhysType& o) const
	{
		return TPhysType<T, D, M>(m_dt - o.m_dt);
	}


	template <int T1, int D1, int M1> 
		TPhysType<T1+T, D1+D, M1+M> operator * (const TPhysType<T1, D1, M1>& o) const
	{
		return TPhysType<T1+T, D1+D, M1+M>(m_dt * o.m_dt);
	}

	template <int T1, int D1, int M1> 
		TPhysType<T-T1, D-D1, M-M1> operator / (const TPhysType<T1, D1, M1>& o) const
	{
		return TPhysType<T-T1, D-D1, M-M1>(m_dt / o.m_dt);
	}

    // friends
    friend std::ostream& operator << (std::ostream& os, const TPhysType& t)
    {
	    return os << t.m_dt;
    }
    
    friend TPhysType operator * (const TPhysType& o, double c)
    {
	    return TPhysType(c * o.m_dt);
    }

    friend TPhysType operator * (double c, const TPhysType& o)
    {
	    return TPhysType(c * o.m_dt);
    }
    
    friend TPhysType operator / (double c, const TPhysType& o)
    {
	    return TPhysType(c / o.m_dt);
    }

    friend TPhysType operator / (const TPhysType& o, double c)
    {
	    return TPhysType(c / o.m_dt);
    }

    // class data. Cannot be private because of template member functions
	double m_dt;
};




#endif // TPhysType_h