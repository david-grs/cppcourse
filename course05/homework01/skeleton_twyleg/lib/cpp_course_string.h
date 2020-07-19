// Some copyright 2020
#pragma once

#include "cpp_course_forward_list.h"

#include <iosfwd>
#include <string>
#include <array>
#include <memory>

#include <list>

namespace cppcourse {

class String
{
public:

	using iter = list<char>::iter;

	String() = default;
	String(const String&);
	String(String&&);
	String(const std::string&);


	bool Empty() const { return (mData.size() == 0); };
	std::size_t Size() const { return mData.size(); };
	
	String& Append(const String&);
	String& Append(char);
	
	iter Erase(const iter&);
	
	char& at(size_t pos);
	bool operator==(const String& rhs) const;
	bool operator!=(const String& rhs) const;

	iter begin() { return mData.begin(); }
	iter end() { return mData.end(); }

	friend std::ostream& operator<<(std::ostream& stream, const String& str);

private:

	list<char> mData;

};

}

