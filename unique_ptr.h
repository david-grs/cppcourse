template <typename T>
class unique_ptr
{
public:
	unique_ptr(T *t)
	{
		val = t;
	}

	T *get()
	{
		return val;
	}

	~unique_ptr()
	{
		if (nullptr != val)
		{
			delete val;
		}
	}

	void reset(T* t)
	{
		T *old = val;
		val = t;
		if (old != nullptr)
		{
			delete old;
		}
	}
	
	T& operator*()
	{
		return *val;
	}

	T* operator->()
	{
		return val;
	}

private:
	T * val;
};
