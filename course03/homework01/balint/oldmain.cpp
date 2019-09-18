#include <algorithm>
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
    if (l) {
      next = std::make_unique<LinkedListInt>(*(l.elem), *(l.next));
    } else {
      next = std::make_unique<LinkedListInt>();
    }
  };

  LinkedListInt(int i) {
    elem = std::make_unique<int>(i);
    next = std::make_unique<LinkedListInt>();
  };

  LinkedListInt() : elem(), next(){};
  std::unique_ptr<int> car() { return std::make_unique<int>(*elem); }

  operator bool() const { return isEmpty(); }

  LinkedListInt cad() const {
    if (isEmpty()) {
      return emptyList();
    }
    if (next->isEmpty()) {
      return emptyList();
    } else {
      // return LinkedListInt(*this->car(), *((*(next)).next));
      return LinkedListInt(*next->car(), *((*(next)).next));
    }
  }

  LinkedListInt &operator=(const LinkedListInt &other) {

    if (other) {
      auto newelem = std::make_unique<int>(*other.elem);
      elem = std::move(newelem);
      if (*(other.next)) {
        auto newnext = std::make_unique<LinkedListInt>(*(*other.next).elem,
                                                       *(*other.next).next);
        next = std::move(newnext);
      }
    }
    return *this;
  }
  LinkedListInt(const LinkedListInt &other) {
    if (other) {
      // LinkedListInt(*(other.elem), *(other.next))
      std::unique_ptr<int> newelem = std::make_unique<int>(*other.elem);
      elem = std::move(newelem);

      if (*(other.next)) {
        auto newnext = std::make_unique<LinkedListInt>(*(*other.next).elem,
                                                       *(*other.next).next);
        next = std::move(newnext);
      } else {
        auto newnext = std::make_unique<LinkedListInt>();
        next = std::move(newnext);
      }
    }
  }
  ~LinkedListInt(){
    elem.reset();
    next.reset();
  }

private:
  std::unique_ptr<int> elem;
  std::unique_ptr<LinkedListInt> next;
};

LinkedListInt cons(int i, LinkedListInt &l) {
  LinkedListInt retval = LinkedListInt(i, l);
  return retval;
};

std::unique_ptr<int> car(LinkedListInt l) { return l.car(); }

LinkedListInt cad(const LinkedListInt &l) { return l.cad(); }

LinkedListInt pushBack(LinkedListInt& orig, int newelem){
  if (orig){
    LinkedListInt tmp1 = cad(orig);
    LinkedListInt tmp2 = pushBack(tmp1, newelem);

    return LinkedListInt(*car(orig), tmp2);
  }
  else{
    return LinkedListInt(newelem);
  }
}

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
  std::cout << "test3 is empty" << std::endl;

  if (test3.isEmpty()) {
    std::cout << "test3 is empty" << std::endl;
  }
  if (!test3) {
    std::cout << "test3 is NOT empty" << std::endl;
  }

  // LinkedListInt test4 = cad(test3);
  LinkedListInt test4 = test3.cad();
  if (test4.isEmpty()) {
    std::cout << "test4 is empty" << std::endl;
  }
  if (!test4.isEmpty()) {
    std::cout << "test4 is NOT empty" << std::endl;
  }

  LinkedListInt test5 = pushBack(test3, 99);
  if (test5.isEmpty()) {
    std::cout << "test5 is empty" << std::endl;
  }
  if (!test5.isEmpty()) {
    std::cout << "test5 is NOT empty" << std::endl;
  }

  return 0;
}
