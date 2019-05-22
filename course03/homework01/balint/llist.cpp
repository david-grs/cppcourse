#include <algorithm>
#include <iostream>
#include <memory>

struct Node {
  int elem;
  std::unique_ptr<Node> next;

  Node() : elem(), next(){};
  Node(int i) : elem(i), next(){};

  ~Node() { next.reset(); }
  Node(const Node &other) {
    if (other.elem) {
      elem = other.elem;
    }
    if (other.next) {
      next = std::make_unique<Node>(*other.next);
    }
  }
  Node &operator=(const Node &other) {
    if (other.elem) {
      elem = other.elem;
    }
    if (other.next) {
      next = std::make_unique<Node>(*other.next);
    }
    return *this;
  }
};

typedef std::unique_ptr<Node> Lst;

class LLint {
public:
  operator bool() const { return list ? list->elem ? true : false : false; }
  ~LLint() { list.reset(); }
  LLint(const LLint &other) { list = std::make_unique<Node>(*other.list); }
  LLint &operator=(const LLint &other) {
    list = other.list ? std::make_unique<Node>( *other.list ): nullptr;
    return *this;
  }
  LLint(const Lst& lst) { list = lst ? std::make_unique<Node>(*lst): nullptr ; }
  LLint(Node n) { list = std::make_unique<Node>(n); }
  Node copyNode(){return Node(*list);}
  Node copyNodeNext(){return Node(*( *list ).next);}
  static LLint emptyList(){return LLint(nullptr);}

  Lst list;
};

int car(const LLint& l){
  if ( l ) {
      return (*l.list).elem;}
  else{
    throw std::runtime_error("Car called on empty list.");
  }
}
LLint cdr(const LLint& l){
  if (l){
    return LLint(l.list->next);
  }
  else{
    return LLint(Node());
  }
}
LLint cons(int i, LLint l){
  // return LLint(*(*l.list).next);
  Node firstNode = Node(i);
  Lst restOfList = l.list ? std::make_unique<Node>(*l.list): nullptr ; 
  firstNode.next = std::move(restOfList);
  return firstNode;
}

int nth(const LLint& l, int i){
  if (i<0){
    throw std::runtime_error("Cant index with negative index");
  }
  if (i==0){
    return car(l);
  }
  else{
    return nth(cdr(l), i-1);
  }
}
