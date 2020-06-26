#include "string.h"

#include <cassert>

void TestEmpty()
{
    String str;
    assert(str.Empty());
}

int main()
{
#ifdef NDEBUG
#error "This file needs to be built with Debug flags"
#endif

    TestEmpty();

    // TODO: other tests

    return 0;
}
