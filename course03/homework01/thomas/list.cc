#include <iostream>
#include <memory>
#include "list.h"

Node::Node(Foo value)
      : mValue{value} {};

Node::Node(Foo value, std::unique_ptr<Node> ptr)
      : next{std::move(ptr)}, mValue{value} {};

  void Node::insert_after(Foo value) {
    std::unique_ptr<Node> new_next =
        std::make_unique<Node>(value, std::move(next));
    next = std::move(new_next);
  }



  void LinkedList::push_back(Foo value) {
    std::unique_ptr<Node> new_node = std::make_unique<Node>(value);

    if (!start) {
      start = std::move(new_node);
    } else {
      Node *next = start.get();
      while (next->next) {
        std::cout << next->getValue().getI() << '\n';
        next = next->next.get();
      }
      next->next = std::move(new_node);
    }
  }

  void LinkedList::print() {
    /* Used raw pointers here. Can see no way of doing it differently (except */
    /*  recursion) */

    if (!start) {
      std::cout << "Empty list" << '\n';
    }

    std::cout << "Foo:" << start->getValue().getI() << '\n';

    Node *next = start->next.get();
    while (next) {
      std::cout << "Foo:" << next->getValue().getI() << '\n';
      next = next->next.get();
    }
  }
  int LinkedList::len() {
    if (!start) {
      return 0;
    } else {
		int n = 1;
      Node *next = start.get();
      while (next->next) {
		  n += 1;
        next = next->next.get();
      }
	  return n;
    }
  }


