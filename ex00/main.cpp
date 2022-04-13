#include "easyfind.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main(void)
{
  std::vector<int> v1;

  for (size_t i = 0; i < 4; i++) {
    v1.push_back(static_cast<int>(i));
  }

  std::cout << *easyfind(v1, 3) << std::endl;
}
