#include "unique_ptr.h"

#include <cassert>
#include <memory>

void TestUniquePtr()
{
    //Test constructor
    UniquePtr<int> u1;
    UniquePtr<int> u2 (nullptr);
    UniquePtr<int> u3 (new int);
    UniquePtr<int> u4 (new int(100));
    assert (u1.get() == nullptr);
    assert (u2.get() == nullptr);
    assert (*u3 == 0);
    assert (*u4 == 100);

    //Operator=
    UniquePtr<int> foo;
    UniquePtr<int> bar;

    foo = UniquePtr<int>(new int (101));
    bar = std::move(foo);      

    assert (foo.get() == nullptr);
    assert(*bar == 101);

    //Get + release
    int* p = nullptr;
    foo = UniquePtr<int>(new int(10));
    bar = std::move(foo);
    p = bar.get();
    *p = 20;
    p = nullptr;
    assert(*bar == 20);
    foo = UniquePtr<int>(new int(30));
    assert(*foo == 30);
    p = foo.release();
    assert(foo.get() == nullptr);
    assert(*p == 30);

    //Reset
    UniquePtr<int> up;
    up.reset (new int);
    *up=5;
    assert(*up == 5);
    up.reset (new int);
    *up=10;
    assert(*up == 10);
    up.reset();
    assert(up.get() == nullptr);

    std::cout << "Done testing unique ptr" << std::endl;
}

int main()
{
#ifdef NDEBUG
#error Compile the code in debug mode!
#endif

    TestUniquePtr();
    return 0;
}
