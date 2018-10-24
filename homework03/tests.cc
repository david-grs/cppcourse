#include "shared_ptr.h"
#include "unique_ptr.h"

#include <cassert>
#include <memory>

void TestSharedPtr()
{
    //test constructor
    SharedPtr<int> p1;
    SharedPtr<int> p2 (nullptr);
    SharedPtr<int> p3 (new int);
    SharedPtr<int> p4 (p3);

    assert(p1.use_count() == 0);
    assert(p2.use_count() == 0);
    assert(p3.use_count() == 1);
    assert(p4.use_count() == 0);

    //test operator=
    SharedPtr<int> foo;
    SharedPtr<int> bar (new int(10));
    foo = bar;                          // copy
    //bar = std::make_shared<int> (20);   // move
    //std::unique_ptr<int> unique (new int(30));
    //foo = std::move(unique);            // move from unique_ptr

    assert(*foo == 20);
    assert(*bar == 30);

    //test get
    int* p = new int (10);
    SharedPtr<int> a (p);

    //a and p point to the same location
    assert(a.get() == p);

    // three ways of accessing the same address:
    assert(*a.get() == 10);
    assert(*a == 10);
    assert(*p == 10);

    //test operator ->
//    SharedPtr<C> foo;
//    SharedPtr<C> bar (new C);

    foo = bar;

//    foo->a = 10;
//    bar->b = 20;

//    if (foo) std::cout << "foo: " << foo->a << ' ' << foo->b << '\n';
//    if (bar) std::cout << "bar: " << bar->a << ' ' << bar->b << '\n';

//    //test operator bool()
//    SharedPtr<int> foo;
//    SharedPtr<int> bar (new int(34));

//    if (foo)
//        std::cout << "foo points to " << *foo << '\n';
//    else std::cout << "foo is null\n";

//    if (bar)
//        std::cout << "bar points to " << *bar << '\n';
//    else std::cout << "bar is null\n";

    //test reset
//    SharedPtr<int> sp;  // empty
//    sp.reset (new int);       // takes ownership of pointer
//    *sp=10;
//    std::cout << *sp << '\n';
//    sp.reset (new int);       // deletes managed object, acquires new pointer
//    *sp=20;
//    std::cout << *sp << '\n';
//    sp.reset();               // deletes managed object

//    SharedPtr<int> p1{new int{1}};
//    std::cout << *p1 << '\n';
//    SharedPtr<int> p2{p1};
//    p1.reset(new int{2});
//    std::cout << *p1.get() << '\n';
//    p1.reset();
//    std::cout << std::boolalpha << static_cast<bool>(p2) << '\n';

}

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

    std::cout << "Swapping..." << std::endl;
    foo = UniquePtr<int>(new int (101));    //calls destructor

    std::cout << "Moving..." << std::endl;
    bar = std::move(foo);       //calls destructor

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
    UniquePtr<int> up;  // empty
    up.reset (new int);       // takes ownership of pointer
    *up=5;
    assert(*up == 5);

    up.reset (new int);       // deletes managed object, acquires new pointer
    *up=10;
    assert(*up == 10);

    up.reset();               // deletes managed object
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
