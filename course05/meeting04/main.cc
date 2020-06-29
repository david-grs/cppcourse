#include <memory>
#include <iostream>
#include <cassert>

// 2 reasons we need dyn mem alloc
//  1) "space" reason: we _need_ to know the size of an object at build time
//  2) "lifetime" / "scope" reason

class String
{
public:
	using value_type = char;
	using size_type = std::size_t;

	String() =default;
	String(const std::string&);

	String(const String&); // copy constructor

	value_type& at(size_type);
	value_type at(size_type) const;

	const value_type* c_str() const { return mBuffer.get(); }
	size_type size() const { return mSize; }
	bool empty() const { return mSize == 0; }

private:
	size_type mSize = 0;
	size_type mCapacity = 0;
	std::unique_ptr<char[]> mBuffer;
};

String::String(const std::string& str) :
	mSize{str.size()}, // initializer list
	mCapacity{mSize + 1},
	mBuffer{std::make_unique<char[]>(mCapacity)}
{
	std::copy(str.cbegin(), str.cend(), mBuffer.get());
	mBuffer[mSize] = 0;
}

String::String(const String& str) :
	mSize{str.mSize},
	mCapacity{str.mCapacity},
	mBuffer{std::make_unique<char[]>(mCapacity)}
{
	std::copy(&str.mBuffer[0], &str.mBuffer[mSize + 1], mBuffer.get());
}

String::value_type& String::at(size_type sz)
{
	if (sz >= mSize)
		throw std::out_of_range("..");
	return mBuffer[sz];
}

String::value_type String::at(size_type sz) const
{
	if (sz >= mSize)
		throw std::out_of_range("..");
	return mBuffer[sz];
}

std::ostream& operator<<(std::ostream& stream, const String& str)
{
	if (!str.empty())
		stream << str.c_str();
	return stream;
}

int main()
{
	String str{"foobarfoobar"};
	std::cout << str << std::endl;

	String str2{str};
	String str3;
	str3 = str;
	str2.at(1) = 'c';
	std::cout << str2 << std::endl;

	return 0;
}

#if 0
struct A
{
	int mI = 123;
};

int main()
{
	auto pa = std::make_unique<A>(); // "unique" ownership

	std::unique_ptr<A> pa2 = std::make_unique<A>();
	pa2->mI = 345;

	std::cout << pa->mI << std::endl; // unique_ptr "RAII" (Resource Acquisition Is Initialization)
	std::cout << pa2->mI << std::endl;
	return 0;
}
#endif
