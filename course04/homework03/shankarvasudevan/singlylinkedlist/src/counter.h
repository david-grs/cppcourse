#pragma once
#include <cstddef>

struct Counter
{
public:
	Counter(std::size_t value) : mValue(value) { ++sCtors; }
	Counter(const Counter&) { ++sCopyCtors; }
	Counter& operator=(const Counter&) { ++sCopyCtors; }
	Counter(Counter&&) { ++sMoveCtors; }
	Counter& operator=(Counter&&) { ++sMoveCtors; }

    static void reset_constructor_count()
    {
        sCtors = 0;
        sCopyCtors = 0;
        sMoveCtors = 0;
    }

	static std::size_t sCtors;
	static std::size_t sCopyCtors;
	static std::size_t sMoveCtors;

	std::size_t get_value() { return mValue; }

private:
    std::size_t mValue;
};