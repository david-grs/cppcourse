#include <memory>

class Foo {
public:
  explicit Foo(int i) : mI{i} {}

  int getI() { return mI; }

private:
  int mI;
};


class Node {
public:
  Node(Foo value);
  Node(Foo value, std::unique_ptr<Node> ptr);

  void insert_after(Foo value);
  Foo getValue() { return mValue; }

  std::unique_ptr<Node> next = nullptr;

private:
  Foo mValue;
};

class LinkedList {
public:
  LinkedList() = default;

  void push_back(Foo value) ;
  void print(); 
  int len(); 
private:
  std::unique_ptr<Node> start = nullptr;
};

