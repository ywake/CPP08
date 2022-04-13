#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &t, int value)
{
  return std::find(t.begin(), t.end(), value);
}

#endif
