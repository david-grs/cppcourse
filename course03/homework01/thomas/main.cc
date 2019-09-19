#include "list.h"
#include <iostream>

int main() {

  LinkedList list;

  Foo foo{5};
  Foo foo2{6};

  list.push_back(foo);
  list.print();
  list.push_back(foo2);
  list.print();

  std::cout << list.len() << '\n';

  return 0;
}
