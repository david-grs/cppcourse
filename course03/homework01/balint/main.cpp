#include "llist.cpp"

// TESTS

int main()
{
  int i;
  Node n = {3};
  Node m = {4};
  Lst tmp = std::make_unique<Node>(m);
  Lst tmp2 = std::make_unique<Node>(n);
  Node m2 = m;
  Node m3 = Node(m);
  // m2.mnext = std::move(m3);
  m2.mnext = std::make_unique<Node>(m3);
  LLint ls1 = LLint(m3);
  LLint ls3 = LLint(n);
  LLint ls2 = ls1;
  ls2.mlist->mnext = std::move(ls3.mlist);
  // LLint ls2_cad = cad(ls2);
  // std::cout<<"car of ls2: "<<car(ls2)<<std::endl;

  LLint consed = cons(100, cons(99, ls1));
  std::cout << "First elem is: " << car(consed) << std::endl;
  std::cout << "Second elem is: " << car(cdr(consed)) << std::endl;
  std::cout << "Third elem is: " << car(cdr(cdr(consed))) << std::endl;
  // Lst n;
  // Lst n = Node(1, Node());
  // Node n = Node();
  if (ls2)
    {
      i = 0;
    }
  else
    {
      i = 1;
    }
  std::cout << "Node is: " << i << std::endl;
}
