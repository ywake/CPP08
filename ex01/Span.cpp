#include "Span.hpp"

#include <algorithm>
#include <stdexcept>

/*
 * Constructor/Destructor
 */
Span::Span(unsigned int N) : _N(N), _nextIdx(0), _nums(N), _spans(N) {}

Span::Span(Span const &copy) :
    _N(copy._N), _nextIdx(copy._nextIdx), _nums(copy._nums), _spans(copy._spans)
{
}

Span::~Span() {}

/*
 * Operators
 */
Span &Span::operator=(Span const &other)
{
  if (this != &other) {
    _N = other._N;
    _nextIdx = other._nextIdx;
    _nums = other._nums;
    _spans = other._spans;
  }
  return *this;
}

/*
 * Getter/Setter
 */

/*
 * Methods
 */
void Span::addNumber(int num)
{
  // add num
  if (_nextIdx >= _N) {
    throw std::range_error("range error.");
  }
  _nums[_nextIdx] = num;

  // calculate span
  if (_nextIdx >= 1) {
    _spans[_nextIdx - 1] = std::abs(_nums[_nextIdx - 1] - num);
  }

  // increment
  ++_nextIdx;
}

void Span::addNumber(std::vector<int>::iterator const begin,
                     std::vector<int>::iterator const end)
{
  for (std::vector<int>::iterator i = begin; i != end; i++) {
    addNumber(*i);
  }
}

unsigned int Span::shortestSpan()
{
  if (_nextIdx < 2) {
    throw std::length_error("too few.");
  }
  return *std::min_element(_spans.begin(), _spans.begin() + _nextIdx - 1);
}

unsigned int Span::longestSpan()
{
  if (_nextIdx < 2) {
    throw std::length_error("too few.");
  }
  return *std::max_element(_spans.begin(), _spans.begin() + _nextIdx - 1);
}

void Span::print(std::ostream &os) const
{
  os << _N << " [";
  for (unsigned int i = 0; i < _nextIdx; i++) {
    os << " " << _nums[i];
  }
  os << " ] / (";
  for (unsigned int i = 1; i < _nextIdx; i++) {
    os << " " << _spans[i - 1];
  }
  os << " )";
}

/*
 * Other Operators
 */
std::ostream &operator<<(std::ostream &os, Span const &span)
{
  span.print(os);
  return os;
}
