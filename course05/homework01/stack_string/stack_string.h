#pragma once

#include <ostream>
#include <string>

namespace cppcourse::homework01 {

class StackString
{
public:
	StackString() {};
	StackString(const std::string&);
	StackString(const char*);

	bool Empty() const;
	std::size_t Size() const;

	const char* GetValue() const;
	std::string ToString() const;

	void Append(const StackString&);

	static const std::size_t MAX_STRING_LENGTH{255};

private:
	int32_t mTop{0};
	char mData[MAX_STRING_LENGTH+1] = {'\0'};
};

inline std::ostream& operator<<(std::ostream& stream, StackString str)
{
    return stream << str.GetValue();
}

}

