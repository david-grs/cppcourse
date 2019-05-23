#include <algorithm>
#include <iostream>
#include <memory>

struct Node
{
  int melem;
  std::unique_ptr<Node> mnext;

  Node() : melem(), mnext(){};
  Node(int i) : melem(i), mnext(){};

  ~Node() { mnext.reset(); }
  Node(const Node &other)
  {
    if (other.melem)
      {
	melem = other.melem;
      }
    if (other.mnext)
      {
	mnext = std::make_unique<Node>(*other.mnext);
      }
  }
  Node &operator=(const Node &other)
  {
    if (other.melem)
      {
	melem = other.melem;
      }
    if (other.mnext)
      {
	mnext = std::make_unique<Node>(*other.mnext);
      }
    return *this;
  }
};

typedef std::unique_ptr<Node> Lst;

class LLint
{
 public:
  operator bool() const { return mlist ? mlist->melem ? true : false : false; }
  ~LLint() { mlist.reset(); }
  LLint(const LLint &other) { mlist = std::make_unique<Node>(*other.mlist); }
  LLint &operator=(const LLint &other)
  {
    mlist = other.mlist ? std::make_unique<Node>(*other.mlist) : nullptr;
    return *this;
  }
  LLint(const Lst &lst) { mlist = lst ? std::make_unique<Node>(*lst) : nullptr; }
  LLint(Node n) { mlist = std::make_unique<Node>(n); }
  Node copyNode() { return Node(*mlist); }
  Node copyNodeMnext() { return Node(*(*mlist).mnext); }
  static LLint emptyList() { return LLint(nullptr); }
  // int operator[](int i) const {return nth(*this, i);}
  int car() const 
  {
    if (*this)
      {
        return (*mlist).melem;
      }
    else
      {
        throw std::runtime_error("Car called on empty mlist.");
      }
  }

  Lst mlist;
};

LLint cdr(const LLint &l)
{
  if (l)
    {
      return LLint(l.mlist->mnext);
    }
  else
    {
      return LLint(Node());
    }
}
LLint cons(int i, LLint l)
{
  // return LLint(*(*l.mlist).mnext);
  Node firstNode = Node(i);
  Lst restOfList = l.mlist ? std::make_unique<Node>(*l.mlist) : nullptr;
  firstNode.mnext = std::move(restOfList);
  return firstNode;
}

int nth(const LLint &l, int i)
{
  if (i < 0)
    {
      throw std::runtime_error("Cant index with negative index");
    }
  if (i == 0)
    {
      return l.car();
    }
  else
    {
      return nth(cdr(l), i - 1);
    }
}

LLint pushBack(const LLint &l, int i)
{
  if (l)
    {
      return cons(l.car(), pushBack(cdr(l), i));
    }
  else
    {
      return LLint(i);
    }
}

int len(const LLint &l)
{
  if (l)
    {
      return 1 + len(cdr(l));
    }
  else
    {
      return 0;
    }
}
