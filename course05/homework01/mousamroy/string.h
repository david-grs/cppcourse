#pragma once

#include <string>
#include <ostream>

class String
{
public:
	String();
	String(const std::string&);

	bool Empty() const;
	std::size_t Size() const;
	char operator[](std::size_t) const;

	// TODO add concat and other functions

private:
	static const std::size_t maxLength = 100;
	char data[maxLength + 1];
};

std::ostream& operator<<(std::ostream& stream, String str);

