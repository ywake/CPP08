#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>

int main(void)
{
  std::vector<int> vec;
  for (size_t i = 0; i < 4; i++) {
    vec.push_back(static_cast<int>(i));
  }
  std::cout << *easyfind(vec, 1) << std::endl;

  std::vector<int> const constVec(vec);
  std::cout << *easyfind(vec, 1) << std::endl;
  try {
    std::cout << "easyfind(vec, 42) : ";
    easyfind(vec, 42);
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::list<int> lst;
  for (size_t i = 0; i < 4; i++) {
    lst.push_back(static_cast<int>(i));
  }
  std::cout << *easyfind(lst, 2) << std::endl;
}
