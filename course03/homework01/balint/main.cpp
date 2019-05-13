#include <iostream>
#include <memory>

class LinkedListInt {
public:
  bool isEmpty() const { return elem ? false : true; }
  LinkedListInt static emptyList() {
    LinkedListInt retval;
    return retval;
  };

  LinkedListInt(int i, LinkedListInt &l) {
    elem = std::make_unique<int>(i);
    if (!*(l.next)) {
      next = std::make_unique<LinkedListInt>();
    } else {
      next = std::make_unique<LinkedListInt>(*(l.elem), *(l.next));
    }
  };

  LinkedListInt(int i) {
    elem = std::make_unique<int>(i);
    next = std::make_unique<LinkedListInt>();
  };

  LinkedListInt() : elem(), next(){};
  std::unique_ptr<int> car(){return std::make_unique<int>(*elem);}

  operator bool() const {return isEmpty();}

private:
  std::unique_ptr<int> elem;
  std::unique_ptr<LinkedListInt> next;
};

LinkedListInt static cons(int i, LinkedListInt &l) {
  LinkedListInt retval = LinkedListInt(i, l);
  return retval;
};

std::unique_ptr<int> car(LinkedListInt l){return l.car();}

int main() {
  LinkedListInt test = LinkedListInt();
  if (test.isEmpty()) {
    std::cout << "test is empty" << std::endl;
  }
  if (!test.isEmpty()) {
    std::cout << "test is NOT empty" << std::endl;
  }

  LinkedListInt test2 = 3;
  if (test2.isEmpty()) {
    std::cout << "test2 is empty" << std::endl;
  }
  if (!test2.isEmpty()) {
    std::cout << "test2 is NOT empty" << std::endl;
  }

  LinkedListInt test3 = {4, test2};
  if (test3.isEmpty()) {
    std::cout << "test3 is empty" << std::endl;
  }
  if (!test3) {
    std::cout << "test3 is NOT empty" << std::endl;
  }

  return 0;
}
