#ifndef TDimension_h
#define TDimension_h

template <int T> class TSimpleType
{
public:
	TSimpleType() : m_dt(0) {}
	TSimpleType(double dt) : m_dt(dt) {}

	TSimpleType& operator = (const TSimpleType& o)
	{
		m_dt = o.m_dt;
		return *this;
	}

	TSimpleType operator + (const TSimpleType& o) const 
	{ 
        return TSimpleType(m_dt + o.m_dt); 
    }

	TSimpleType operator - (const TSimpleType& o) const 
	{ 
        return TSimpleType(m_dt - o.m_dt); 
    }

	TSimpleType operator * (const TSimpleType& o) const 
	{ 
        return TSimpleType(m_dt * o.m_dt); 
    }

	TSimpleType operator / (const TSimpleType& o) const 
	{ 
        return TSimpleType(m_dt / o.m_dt); 
    }

	// if this line (friend) is uncommented, VC links, but BC does not, 
    // by some reason it cannot find function definition.
    friend std::ostream& operator << (std::ostream& os, const TSimpleType& t)
    {
	    return os << t.m_dt;
    }

private:
	double m_dt;
};

#endif // TDimension_h
