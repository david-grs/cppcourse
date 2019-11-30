#pragma once
#include <utility>

class unique_ptr_int
{
public:
    unique_ptr_int() : mPtr{nullptr} {}
    unique_ptr_int(int* data) : mPtr{data} {}
    unique_ptr_int(unique_ptr_int&& uniquePtr): mPtr(uniquePtr.mPtr) { uniquePtr.mPtr = nullptr; }

    ~unique_ptr_int() { if (mPtr != nullptr) { delete mPtr; }}

    int& operator*() const { return *mPtr; }
    int* operator->() const { return mPtr; }
    unique_ptr_int& operator=(unique_ptr_int uniquePtr);

    int* Get() const { return mPtr; }
    int* Release();

private:
    int* mPtr;
};
