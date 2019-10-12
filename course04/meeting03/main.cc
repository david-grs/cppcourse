#include <iostream>
#include <array>
#include <cassert>

class String
{
public:
	static constexpr const std::size_t MaxSize = 32;

	String();
	String(const std::string&);

	//~String();

	//String(const String&);
	//String& operator=(const String&);

	std::size_t size() const { return mSize; }
	std::size_t max_size() const { return MaxSize; }
	std::size_t capacity() const { return MaxSize; }

	const char* c_str() const { return mData.data(); }

	char at(std::size_t idx) const { return mData.at(idx); }

private:
	std::size_t mSize = 0;
	std::array<char, MaxSize> mData;
};

String::String()
{
	mData[0] = 0;
}

String::String(const std::string& str) :
	mSize{str.size()}
{
	if (mSize + 1 > max_size())
		throw std::out_of_range("...");

	std::copy(str.data(), str.data() + mSize + 1, mData.data());
}

/*
String::String(const String& other) :
	mSize{other.mSize},
	mData{other.mData}
{
}

String& String::operator=(const String& other)
{
	mSize = other.mSize;
	mData = other.mData;
	return *this;
}
*/

std::ostream& operator<<(std::ostream& stream, const String& str)
{
	stream << str.c_str();
	return stream;
}

int main()
{
	String s(std::string("foofoofoofoofoofoofoofoofoo"));
	std::cout << s << std::endl;

	String ss(s);
	std::cout << ss << std::endl;

	String sss;
	sss = s;
	std::cout << sss << std::endl;

	return 0;
}

