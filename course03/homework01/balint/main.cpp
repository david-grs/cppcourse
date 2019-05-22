#include "llist.cpp"

// TESTS

int main() {
  int i;
  Node n = {3};
  Node m = {4};
  Lst tmp = std::make_unique<Node>(m);
  Lst tmp2 = std::make_unique<Node>(n);
  Node m2 = m;
  Node m3 = Node(m);
  // m2.next = std::move(m3);
  m2.next = std::make_unique<Node>(m3);
  LLint ls1 = LLint(m3);
  LLint ls3 = LLint(n);
  LLint ls2 = ls1;
  ls2.list->next = std::move(ls3.list);
  // LLint ls2_cad = cad(ls2);
  ls2 = ls3;
  // std::cout<<"car of ls2: "<<car(ls2)<<std::endl;
  Node  m33;
  LLint l33 = m;
  LLint l34 = cdr(l33);
  if (l33.list==nullptr){
    std::cout<<"Nullptr"<<std::endl;
  }
  else{
    std::cout<<"not nullptr"<<std::endl;}

  // Lst n;
  // Lst n = Node(1, Node());
  // Node n = Node();
  if (ls2) {
    i = 0;
  } else {
    i = 1;
  }
  std::cout << "Node is: " << i << std::endl;
}
