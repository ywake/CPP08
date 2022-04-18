#ifndef SPAN_HPP
#define SPAN_HPP

#include <ostream>
#include <vector>

class Span
{
private:
  unsigned int _N;
  unsigned int _nextIdx;
  std::vector<int> _nums;
  std::vector<int> _spans;

public:
  /*
   * Constructor/Destructor
   */
  Span(unsigned int N = 0);
  Span(Span const &copy);
  ~Span();

  /*
   * Operators
   */
  Span &operator=(Span const &other);

  /*
   * Getter/Setter
   */

  /*
   * Methods
   */
  void addNumber(int num);
  void addNumber(std::vector<int>::iterator const bigin,
                 std::vector<int>::iterator const end);
  unsigned int shortestSpan();
  unsigned int longestSpan();
  void print(std::ostream &os) const;
};

std::ostream &operator<<(std::ostream &os, Span const &span);

#endif /* SPAN_HPP */
