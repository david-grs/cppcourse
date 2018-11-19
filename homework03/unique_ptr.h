#include <iostream>
#include <algorithm>
#pragma once

template <class T>
class UniquePtr
{
public:
    UniquePtr():
        mPtr(nullptr)
    {}

    explicit UniquePtr(T* ptr):
        mPtr(ptr)
    {}

    UniquePtr(UniquePtr&& uniquePtr):
        mPtr(uniquePtr.mPtr)
    {
        uniquePtr.mPtr = nullptr;
    }

    ~UniquePtr()
    {
        mPtr = nullptr;
    }

   inline T* operator->() const
    {
        return mPtr;
    }

    inline T& operator*() const
    {
        return *mPtr;
    }

    inline operator bool() const
    {
        return (mPtr != nullptr);
    }

    inline T* get() const
    {
        return mPtr;
    }

    UniquePtr& operator=(UniquePtr uniquePtr)
    {
        std::swap(mPtr, uniquePtr.mPtr);
        uniquePtr.mPtr = nullptr;
        return *this;
    }

    T* release()
    {
        T* val;
        std::swap(val, mPtr);
        mPtr = nullptr;
        return val;
    }

    void reset()
    {
        mPtr = nullptr;
    }

    void reset(T* ptr)
    {
        std::swap(mPtr, ptr);
    }

private:
    T* mPtr;
};
