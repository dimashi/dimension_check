template <class T, class ImplType> class TParamType
{
public:

	TParamType() : m_dt(0) {}
	TParamType(const ImplType& dt) : m_dt(dt) {}
	TParamType(const TParamType& o) : m_dt(o.m_dt) {}

	TParamType& operator = (const TParamType& o)
	{
		m_dt = o.m_dt;
		return *this;
	}

	template <class T1>
		TParamType< TOper<T, T1>::add, ImplType>
	operator + (const TParamType<T1, ImplType>& o) const
	{
        return TParamType<TOper<T, T1>::add, ImplType>(m_dt + o.m_dt);
	}
	
	template <class T1>
	TParamType< TOper<T, T1>::subtract, ImplType> operator - (const TParamType<T1, ImplType>& o) const
	{
		return TParamType<TOper<T, T1>::subtract, ImplType>(m_dt - o.m_dt);
	}

	template <class T1> 
	TParamType<TOper<T, T1>::multiply, ImplType> operator * (const TParamType<T1, ImplType>& o) const
	{
		return TParamType<TOper<T, T1>::multiply, ImplType>(m_dt * o.m_dt);
	}

	template <class T1> 
	TParamType<TOper<T, T1>::divide, ImplType> operator / (const TParamType<T1, ImplType>& o) const
	{
		return TParamType<TOper<T, T1>::divide, ImplType>(m_dt / o.m_dt);
	}

    // friend std::ostream& operator << (std::ostream&, const TParamType&);
    // operator ImplType& ()  { return m_dt; }

	ImplType m_dt;

private:
    T m_t;   // constructor verifies that T is valid, See T constructor
};

template <class T, class ImplType> 
std::ostream& operator << (std::ostream& os, 
						   const TParamType<T, ImplType>& t)
{
	return os << t.m_dt;
}


template <class T, class ImplType> TParamType<TOper<T, T>::multiplyScalar, ImplType> 
operator * (const ImplType& c, const TParamType<T, ImplType>& o)
{
	return TParamType<TOper<T, T>::multiplyScalar, ImplType>(c * o.m_dt);
}

template <class T, class ImplType> TParamType<TOper<T, T>::multiplyScalar, ImplType> 
operator * (const TParamType<T, ImplType>& o, const ImplType& c)
{
	return TParamType<TOper<T, T>::multiplyScalar, ImplType>(c * o.m_dt);
}

template <class T, class ImplType> TParamType<TOper<T, T>::divideScalar, ImplType> 
operator / (const ImplType& c, const TParamType<T, ImplType>& o)
{
	return TParamType<T, ImplType>(c / o.getValue());
}

template <class T, class ImplType> TParamType<TOper<T, T>::divideScalar, ImplType> 
operator / (const TParamType<T, ImplType>& o, const ImplType& c)
{
	return TParamType<TOper<T, T>::divideScalar, ImplType>(c / o.m_dt);
}

template <class T, class ImplType> TParamType<TOper<T, T>::sqrt, ImplType> 
sqrt(const TParamType<T, ImplType>& o)
{
    return TParamType<TOper<T, T>::sqrt, ImplType>(sqrt(o.m_dt));
}

template <class T, class ImplType> TParamType<TOper<T, T>::exp, ImplType> 
exp(const TParamType<T, ImplType>& o)
{
    return TParamType<TOper<T, T>::sqrt, ImplType>(exp(o.m_dt));
}

template <class T, class ImplType> TParamType<TOper<T, T>::abs, ImplType> 
abs(const TParamType<T, ImplType>& o)
{
    return TParamType<TOper<T, T>::abs, ImplType>(abs(o.m_dt));
}


template <class T, class ImplType> TParamType<TOper<T, T>::conj, ImplType> 
conj(const TParamType<T, ImplType>& o)
{
    return TParamType<TOper<T, T>::conj, ImplType>(conj(o.m_dt));
}

