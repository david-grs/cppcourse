#pragma once

#include <string>
#include <boost/optional.hpp>
#include <iostream>

namespace CppCourse { namespace TupleHomework {

template<class Head, class... Args>
class Tuple : public Tuple<Args...> {
public:
    Tuple(Head head, Args... args)
    :   Tuple<Args...>(args...),
        mArgs(Tuple<Args...>(args...)),
        mHead(head)
    {
    }

    int Size()
    {
        return SizeHelper(mHead, mArgs);
    }

    Head Get(int index)
    {
        if (index == 0)
            return mHead;

        return mArgs.Get(--index);
    }

private:
    int SizeHelper(Head head, Tuple<Args...> tuple)
    {
        return 1 + tuple.Size();
    }

private:
    Head mHead;
    Tuple<Args...> mArgs;
};

template<class Head>
class Tuple<Head> {
public:
    Tuple(Head head) : mHead(head) {}

    int Size()
    {
        return 1;
    }

    Head Get(int index)
    {
        if (index == 0)
            return mHead;

        throw std::runtime_error("tuple index out of bounds");
    }

private:
    Head mHead;
};

}};
