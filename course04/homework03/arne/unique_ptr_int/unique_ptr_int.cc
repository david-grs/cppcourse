#include "unique_ptr_int.h"
#include <utility>


unique_ptr_int& unique_ptr_int::operator=(unique_ptr_int uniquePtr)
{
    mPtr = std::move(uniquePtr.mPtr);
    uniquePtr.mPtr = nullptr;
    return *this;
}

int* unique_ptr_int::Release()
{
    int* data;
    data = std::move(mPtr);
    mPtr = nullptr;
    return data;
}
