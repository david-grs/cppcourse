#pragma once
#include <cstddef>

struct Foo
{
    public:
        static std::size_t copy_constructor_count;
        Foo(const Foo& other) : mFoo(0)
        {
            ++copy_constructor_count;
        }

        static void reset_constructor_count()
        {
            copy_constructor_count = 0;
        }

        Foo(std::size_t fooValue) : mFoo(fooValue) {}        
        std::size_t get_foo() { return mFoo; }

    private:
        std::size_t mFoo;   
};