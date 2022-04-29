#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &t, int value)
{
  typename T::iterator res = std::find(t.begin(), t.end(), value);
  if (res == t.end()) {
    throw std::logic_error("Not found.");
  }
  return res;
}

#endif
