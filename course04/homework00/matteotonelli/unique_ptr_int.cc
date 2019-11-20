#include "unique_ptr_int.h"

UniquePtrInt UniquePtrInt::make_unique_int(int value)
{
    return UniquePtrInt(value);
}

std::ostream& operator<<(std::ostream& stream, const UniquePtrInt& ptr)
{
    stream << ptr << " ";
    return stream;
}
