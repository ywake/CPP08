#include "MutantStack.hpp"

#include <iomanip>
#include <iostream>
#include <string>

#define WIDTH 15

void log(std::string const title, MutantStack<int> &mstack)
{
  std::cout << "\033[2m" << std::setw(WIDTH) << std::left << "[" + title + "]"
            << "[ ";

  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  while (it != ite) {
    std::cout << *it << " ";
    ++it;
  }

  std::cout << ">\033[0m" << std::endl;
}

int main()
{
  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);

  log("top", mstack);
  std::cout << mstack.top() << std::endl;

  mstack.pop();

  log("size", mstack);
  std::cout << mstack.size() << std::endl;

  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  //[...]
  mstack.push(0);
  log("push", mstack);

  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();

  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }

  std::cout << "\nstd::stack" << std::endl;
  std::stack<int> s(mstack);
  while (s.size()) {
    std::cout << s.top() << std::endl;
    s.pop();
  }

  {
    std::cout << "\ncheck coplien" << std::endl;
    MutantStack<int> copy(mstack);
    log("copy", copy);
    MutantStack<int> assign;
    log("assign init", assign);
    assign.push(42);
    log("push", assign);
    assign = mstack;
    log("overwrite", assign);
    copy.push(42);
    log("deep(copy)", copy);
    log("deep(mstack)", mstack);
  }

  return 0;
}
