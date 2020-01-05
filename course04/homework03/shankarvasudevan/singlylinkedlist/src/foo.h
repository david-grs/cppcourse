#pragma once

struct Foo
{
    public:
        static std::size_t copy_constructor_count;

        Foo(const Foo& other) : mFoo(0)
        {
            ++copy_constructor_count;
        }

        Foo(std::size_t fooValue) : mFoo(fooValue) {}

        static void reset_copy_constructor_count()
        {
            copy_constructor_count = 0;
        }

        std::size_t get_foo() { return mFoo; }

    private:
        std::size_t mFoo;   
};