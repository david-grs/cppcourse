#include <iostream>
class LinkedListInt{
public:
  bool isEmpty() const {
    std::cout<<"element is: "<<elem<<std::endl;
    return elem ? false : true;
  }
  LinkedListInt static emptyList()  {
    LinkedListInt retval;
    return retval;};

  LinkedListInt static cons(LinkedListInt, int)  {
    LinkedListInt retval;
    return retval;};
  
  // LinkedListInt(int i, LinkedListInt l): elem(std::make_unique<int>(i)),next(std::make_unique<LinkedListInt>(l)) {};
  LinkedListInt(int i, LinkedListInt l): elem(std::make_unique<int>(i)),next(std::make_unique<LinkedListInt>(emptyList())) {};

  LinkedListInt(int i): elem(std::make_unique<int>(i)),next(std::make_unique<LinkedListInt>()) {
    std::cout<<"element is: "<<i<<std::endl;};

  LinkedListInt(): elem(),next() {};
private:
  std::unique_ptr<int> elem;
  std::unique_ptr<LinkedListInt> next;

};

int main(){
  LinkedListInt test =LinkedListInt();
  if (test.isEmpty()){std::cout<<"test is empty"<<std::endl;}
  if (!test.isEmpty()){std::cout<<"test is NOT empty"<<std::endl;}

  LinkedListInt test2 =3;
  if (test2.isEmpty()){std::cout<<"test2 is empty"<<std::endl;}
  if (!test2.isEmpty()){std::cout<<"test2 is NOT empty"<<std::endl;}

  LinkedListInt test3 ={4, test2};
  if (test3.isEmpty()){std::cout<<"test3 is empty"<<std::endl;}
  if (!test3.isEmpty()){std::cout<<"test3 is NOT empty"<<std::endl;}

  return 0;
}
