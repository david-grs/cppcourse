#include <iostream>
#include <array>
#include <string>
#include <stdexcept>

class String
{
public:
	String() :
		mSize(0)
	{}

	String(const std::string& str) :
		mSize(str.size())
	{
		if (str.size() > mData.size())
		{
			throw std::out_of_range("..");
		}

		for (std::size_t i = 0; i < str.size(); ++i)
		{
			mData[i] = str[i];
		}
	}

	std::size_t size() const
	{
		return mSize;
	}

	char at(std::size_t i) const
	{
		return mData.at(i);
	}

private:
	std::array<char, 128> mData;
	std::size_t mSize;
};

std::ostream& operator<<(std::ostream& stream, const String& str)
{
	for (std::size_t i = 0; i < str.size(); ++i)
	{
		stream << str.at(i);
	}
	return stream;
}

int main()
{
	const String str("foobar");

	std::cout << str << std::endl;
	std::cout << str.size() << std::endl;

	return 0;
}


