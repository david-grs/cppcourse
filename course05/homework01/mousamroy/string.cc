#include "string.h"

String::String()
{
	data[0] = 0;
}

String::String(const std::string& str)
{
	if (str.size() > maxLength)
	{
		throw std::invalid_argument("max string length exceeded");
	}

	std::size_t i;
	for (i = 0; i < str.size(); ++i)
	{
		data[i] = str[i];
	}

	data[i] = 0;
}

bool String::Empty() const
{
	return Size() == 0;
}

std::size_t String::Size() const
{
	for (std::size_t i = 0; i <= maxLength; ++i)
	{
		if (data[i] == 0)
			return i;
	}
	throw std::runtime_error("end-of-string character not found");
}

char String::operator[](size_t index) const
{
	if (index > Size())
	{
		throw std::runtime_error("string index exceeded length");
	}

	return data[index];
}


std::ostream& operator<<(std::ostream& stream, String str)
{
	size_t size = str.Size();
	for (std::size_t i = 0; i < size; ++i)
	{
		stream << str[i];
	}
	return stream;
}