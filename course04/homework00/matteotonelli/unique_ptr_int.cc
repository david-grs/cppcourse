#include "unique_ptr_int.h"

UniquePtrInt::~UniquePtrInt(){
    if (mInteger != nullptr)
        delete mInteger;
}

std::ostream& operator<<(std::ostream& stream, const UniquePtrInt& ptr)
{
    stream << ptr.get() << " ";
    return stream;
}

void UniquePtrInt::give_ownership_to(UniquePtrInt& newPtr)
{
    newPtr.mInteger = mInteger;
    mInteger = nullptr;
}
